/*****************************************************************************************
 * arch/arm/mach-rkxx/baord-xxx-sdmmc-config.c
 *
 * Copyright (C) 2013 ROCKCHIP, Inc.
 *
 * Description: 
 *     define the gpio for SD-MMC-SDIO-Wifi functions  according to your own projects.
 *
 * Author: Michael Xie
 *         15 Jan,2013
 * E-mail: xbw@rock-chips.com
 *
 ******************************************************************************************/

#define DS1006H_V1_2_SUPPORT  1

/*
** If you select the macro of CONFIG_SDMMC0_RK29_WRITE_PROTECT, You must define the following values.
** Otherwise, there is no need to define the following values。
*/
//#define SDMMC0_WRITE_PROTECT_PIN	            RK30_PIN3_PB2	//According to your own project to set the value of write-protect-pin.
//#define SDMMC0_WRITE_PROTECT_ENABLE_VALUE     GPIO_HIGH

/*
** If you select the macro of CONFIG_SDMMC1_RK29_WRITE_PROTECT, You must define the following values.
** Otherwise, there is no need to define the following values。
*/
//#define SDMMC1_WRITE_PROTECT_PIN	            RK30_PIN3_PB3	//According to your own project to set the value of write-protect-pin.
//#define SDMMC1_WRITE_PROTECT_ENABLE_VALUE     GPIO_HIGH
    
/*
** If you select the macro of CONFIG_RK29_SDIO_IRQ_FROM_GPIO, You must define the following values.
** Otherwise, there is no need to define the following values。
*/
//#define RK29SDK_WIFI_SDIO_CARD_INT         RK30_PIN3_PD2


/*
* define sdcard PowerEn-pin
*/
#define RK29SDK_SD_CARD_PWR_EN                  RK30_PIN3_PA1
#define RK29SDK_SD_CARD_PWR_EN_LEVEL            GPIO_LOW 
int rk31sdk_get_sdmmc0_pin_io_voltage(void)
{
    int voltage;
#define RK31SDK_SET_SDMMC0_PIN_VOLTAGE

    /**************************************************************************************
    **  Please tell me how much voltage of your SDMMC0-pin in your project. 
    **
    **     例如: 有的项目，它的SDMMC0所在的RK主控的IO组，想用1.8V, 而卡本身用3.3V, 
    **  而中间通过个电平转换.那么，您此时，应该设置下面的voltage值为 1.8V(即1800mv)
    ***************************************************************************************/
    voltage = 3300;  //default the voltage 3300mv. 

    return voltage;
}

/*
* define the card-detect-pin.
*/
#define RK29SDK_SD_CARD_DETECT_N                RK30_PIN3_PB0  //According to your own project to set the value of card-detect-pin.
#define RK29SDK_SD_CARD_INSERT_LEVEL            GPIO_LOW       // set the voltage of insert-card. Please pay attention to the default setting.


/*
* Define wifi module's power and reset gpio, and gpio sensitive level.
* Please set the value according to your own project.
*
* Well, you just own engineering module to set the value in the corresponding module branch.
* Otherwise, you do not define this macro, eliminate it.
*
*/

          
    
#if defined(CONFIG_BCM4329) || defined(CONFIG_BCM4319) || defined(CONFIG_RKWIFI) \
	|| defined(CONFIG_RTL8189ES)

/* wifi-power */
    #define RK30SDK_WIFI_GPIO_POWER_N                  280                 
    #define RK30SDK_WIFI_GPIO_POWER_ENABLE_VALUE       GPIO_HIGH                   
/* wifi-reset */
    #define RK30SDK_WIFI_GPIO_RESET_N                  231
    #define RK30SDK_WIFI_GPIO_RESET_ENABLE_VALUE       GPIO_HIGH 

/* don't care */
   #define RK30SDK_WIFI_GPIO_WIFI_INT_B                238
   #define RK30SDK_WIFI_GPIO_WIFI_INT_B_ENABLE_VALUE   GPIO_HIGH

 
   #define RK30SDK_WIFI_GPIO_BGF_INT_B                236
   #define RK30SDK_WIFI_GPIO_BGF_INT_B_ENABLE_VALUE   GPIO_HIGH


#pragma message HSTR(RK30SDK_WIFI_GPIO_POWER_N)
#pragma message HSTR(RK30SDK_WIFI_GPIO_RESET_N)
#pragma message HSTR(RK30SDK_WIFI_GPIO_WIFI_INT_B)


#endif 

int rk31sdk_get_sdio_wifi_voltage(void)
{
    int voltage;
    
    /******************************************************************************
    **  Please tell me how much wifi-module uses voltage in your project.  
    ******************************************************************************/
#if defined(CONFIG_BCM4329) || defined(CONFIG_BCM4319) || defined(CONFIG_RKWIFI)
    voltage = 1800 ; //power 1800mV
    
#elif defined(CONFIG_MT5931_MT6622)||defined(CONFIG_MT5931)
    voltage = 2800 ; //power 1800V
#elif defined(CONFIG_MT6620) 
    voltage = 2800 ; //power 2800V
#elif defined(CONFIG_RDA5990)||defined(CONFIG_RTL8723AS) || defined(CONFIG_RTL8189ES) 
    voltage = 3300 ; //power 3300V
#else
    //default, sdio use 3.0V
    voltage = 3000 ; //power 3000V
#endif

    return voltage;
}


   
