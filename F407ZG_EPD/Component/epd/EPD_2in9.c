/*****************************************************************************
* | File      	:  	EPD_2in9.c
* | Author      :   Waveshare team
* | Function    :   2.9inch e-paper
* |	This version:   V3.0
* | Date        :   2019-06-12
******************************************************************************/
#include "EPD_2in9.h"
#include "Debug.h"

const unsigned char EPD_2IN9_lut_full_update[] = {
    0x50, 0xAA, 0x55, 0xAA, 0x11, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char EPD_2IN9_lut_partial_update[] = {
    0x10, 0x18, 0x18, 0x08, 0x18, 0x18,
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x13, 0x14, 0x44, 0x12,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/******************************************************************************
function :	Software reset
parameter:
******************************************************************************/
static void EPD_2IN9_Reset(void)
{
    DEV_Digital_Write(EPD_RST_PIN, 1);
    wait_ms(200);
    DEV_Digital_Write(EPD_RST_PIN, 0);
    wait_ms(2);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    wait_ms(200);
}

/******************************************************************************
function :	send command
parameter:
     Reg : Command register
******************************************************************************/
static void EPD_2IN9_SendCommand(uint8_t Reg)
{
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    EPD_SPI_WriteByte(Reg);
    DEV_Digital_Write(EPD_CS_PIN, 1);
}

/******************************************************************************
function :	send data
parameter:
    Data : Write data
******************************************************************************/
static void EPD_2IN9_SendData(uint8_t Data)
{
    DEV_Digital_Write(EPD_DC_PIN, 1);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    EPD_SPI_WriteByte(Data);
    DEV_Digital_Write(EPD_CS_PIN, 1);
}

/******************************************************************************
function :	Wait until the busy_pin goes LOW
parameter:
******************************************************************************/
void EPD_2IN9_ReadBusy(void)
{
    Debug("e-Paper busy\r\n");
    while(DEV_Digital_Read(EPD_BUSY_PIN) == 1) {      //LOW: idle, HIGH: busy
        wait_ms(100);
    }
    Debug("e-Paper busy release\r\n");
}

/******************************************************************************
function :	Setting the display window
parameter:
******************************************************************************/
static void EPD_2IN9_SetWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend)
{
    EPD_2IN9_SendCommand(0x44); // SET_RAM_X_ADDRESS_START_END_POSITION
    EPD_2IN9_SendData((Xstart >> 3) & 0xFF);
    EPD_2IN9_SendData((Xend >> 3) & 0xFF);

    EPD_2IN9_SendCommand(0x45); // SET_RAM_Y_ADDRESS_START_END_POSITION
    EPD_2IN9_SendData(Ystart & 0xFF);
    EPD_2IN9_SendData((Ystart >> 8) & 0xFF);
    EPD_2IN9_SendData(Yend & 0xFF);
    EPD_2IN9_SendData((Yend >> 8) & 0xFF);
}

/******************************************************************************
function :	Set Cursor
parameter:
******************************************************************************/
static void EPD_2IN9_SetCursor(uint16_t Xstart, uint16_t Ystart)
{
    EPD_2IN9_SendCommand(0x4E); // SET_RAM_X_ADDRESS_COUNTER
    EPD_2IN9_SendData((Xstart >> 3) & 0xFF);

    EPD_2IN9_SendCommand(0x4F); // SET_RAM_Y_ADDRESS_COUNTER
    EPD_2IN9_SendData(Ystart & 0xFF);
    EPD_2IN9_SendData((Ystart >> 8) & 0xFF);
}

/******************************************************************************
function :	Turn On Display
parameter:
******************************************************************************/
static void EPD_2IN9_TurnOnDisplay(void)
{
    EPD_2IN9_SendCommand(0x22); // DISPLAY_UPDATE_CONTROL_2
    EPD_2IN9_SendData(0xC4);
    EPD_2IN9_SendCommand(0x20); // MASTER_ACTIVATION
    EPD_2IN9_SendCommand(0xFF); // TERMINATE_FRAME_READ_WRITE

    EPD_2IN9_ReadBusy();
}

/******************************************************************************
function :	Initialize the e-Paper register
parameter:
******************************************************************************/
void EPD_2IN9_Init(uint8_t Mode)
{
    EPD_2IN9_Reset();

    EPD_2IN9_SendCommand(0x01); // DRIVER_OUTPUT_CONTROL
    EPD_2IN9_SendData((EPD_2IN9_HEIGHT - 1) & 0xFF);
    EPD_2IN9_SendData(((EPD_2IN9_HEIGHT - 1) >> 8) & 0xFF);
    EPD_2IN9_SendData(0x00); // GD = 0; SM = 0; TB = 0;
	
    EPD_2IN9_SendCommand(0x0C); // BOOSTER_SOFT_START_CONTROL
    EPD_2IN9_SendData(0xD7);
    EPD_2IN9_SendData(0xD6);
    EPD_2IN9_SendData(0x9D);
	
    EPD_2IN9_SendCommand(0x2C); // WRITE_VCOM_REGISTER
    EPD_2IN9_SendData(0xA8); // VCOM 7C
	
    EPD_2IN9_SendCommand(0x3A); // SET_DUMMY_LINE_PERIOD
    EPD_2IN9_SendData(0x1A); // 4 dummy lines per gate
	
    EPD_2IN9_SendCommand(0x3B); // SET_GATE_TIME
    EPD_2IN9_SendData(0x08); // 2us per line
	
    EPD_2IN9_SendCommand(0x3C); // BORDER_WAVEFORM_CONTROL
    EPD_2IN9_SendData(0x03);                     
    EPD_2IN9_SendCommand(0x11); // DATA_ENTRY_MODE_SETTING
    EPD_2IN9_SendData(0x03);

    //set the look-up table register
    EPD_2IN9_SendCommand(0x32); // WRITE_LUT_REGISTER
    if(Mode == EPD_2IN9_FULL){
        for (uint16_t i = 0; i < 30; i++) {
                EPD_2IN9_SendData(EPD_2IN9_lut_full_update[i]);
        }
    }else if(Mode == EPD_2IN9_PART){
        for (uint16_t i = 0; i < 30; i++) {
                EPD_2IN9_SendData(EPD_2IN9_lut_partial_update[i]);
        }
    }else{
        Debug("error, the Mode is EPD_2IN9_FULL or EPD_2IN9_PART");
    }
}

/******************************************************************************
function :	Clear screen
parameter:
******************************************************************************/
void EPD_2IN9_Clear(void)
{
    uint16_t Width, Height;
    Width = (EPD_2IN9_WIDTH % 8 == 0)? (EPD_2IN9_WIDTH / 8 ): (EPD_2IN9_WIDTH / 8 + 1);
    Height = EPD_2IN9_HEIGHT;
    EPD_2IN9_SetWindows(0, 0, EPD_2IN9_WIDTH, EPD_2IN9_HEIGHT);
    for (uint16_t j = 0; j < Height; j++) {
        EPD_2IN9_SetCursor(0, j);
        EPD_2IN9_SendCommand(0x24);
        for (uint16_t i = 0; i < Width; i++) {
            EPD_2IN9_SendData(0XFF);
        }
    }
    EPD_2IN9_TurnOnDisplay();
}

/******************************************************************************
function :	Sends the image buffer in RAM to e-Paper and displays
parameter:
******************************************************************************/
void EPD_2IN9_Display(uint8_t *Image)
{
    uint16_t Width, Height;
    Width = (EPD_2IN9_WIDTH % 8 == 0)? (EPD_2IN9_WIDTH / 8 ): (EPD_2IN9_WIDTH / 8 + 1);
    Height = EPD_2IN9_HEIGHT;

    uint32_t Addr = 0;
    // uint32_t Offset = ImageName;
    EPD_2IN9_SetWindows(0, 0, EPD_2IN9_WIDTH, EPD_2IN9_HEIGHT);
    for (uint16_t j = 0; j < Height; j++) {
        EPD_2IN9_SetCursor(0, j);
        EPD_2IN9_SendCommand(0x24);
        for (uint16_t i = 0; i < Width; i++) {
            Addr = i + j * Width;
            EPD_2IN9_SendData(Image[Addr]);
        }
    }
    EPD_2IN9_TurnOnDisplay();
}

/******************************************************************************
function :	Enter sleep mode
parameter:
******************************************************************************/
void EPD_2IN9_Sleep(void)
{
    EPD_2IN9_SendCommand(0x10);
    EPD_2IN9_SendData(0x01);
    // EPD_2IN9_ReadBusy();
}
