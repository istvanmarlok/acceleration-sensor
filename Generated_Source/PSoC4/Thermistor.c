/*******************************************************************************
* File Name: Thermistor.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the ThermistorCalc
*  Component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Thermistor.h"


/*******************************************************************************
* Function Name: Thermistor_GetResistance
********************************************************************************
*
* Summary:
*  The digital values of the voltages across the reference resistor and the
*  thermistor are passed to this function as parameters. The function returns
*  the resistance, based on the voltage values.
*
* Parameters:
*  vReference: the voltage across the reference resistor;
*  vThermistor: the voltage across the thermistor.
*  The ratio of these two voltages is used by this function. Therefore, the
*  units for both parameters must be the same.
*
* Return:
*  The return value is the resistance across the thermistor. The value returned
*  is the resistance in Ohms.
*
*******************************************************************************/
uint32 Thermistor_GetResistance(int16 vReference, int16 vThermistor)
                                      
{
    int32 resT;
    int16 temp;

    /* Calculate thermistor resistance from the voltages */
    resT = Thermistor_REF_RESISTOR * ((int32)vThermistor);
    if (vReference < 0)
    {
        temp = -vReference;
        temp = (int16)((uint16)((uint16)temp >> 1u));
        temp = -temp;
    }
    else
    {
        temp = (int16)((uint16)((uint16)vReference >> 1u));
    }
    resT += temp;
    resT /= vReference;

    /* The ordering of Reference resistor value is specifically designed to keep the result from overflowing */
    return ((uint32)((uint32)resT << Thermistor_REF_RES_SHIFT));
}


/*******************************************************************************
* Function Name: Thermistor_GetTemperature
********************************************************************************
*
* Summary:
*  The value of the thermistor resistance is passed to this function as a
*  parameter. The function returns the temperature, based on the resistance
*  value. The method used to calculate the temperature is dependent on whether
*  Equation or LUT was selected in the Customizer.
*
* Parameters:
*  resT: the resistance across the thermistor in Ohms.
*
* Return:
*  The return value is the temperature in 1/100ths of degrees C. For example,
*  the return value is 2345, when the actual temperature is 23.45 degrees C.
*
*******************************************************************************/
int16 Thermistor_GetTemperature(uint32 resT) 
{
    int16 tempTR;
    static const uint32 CYCODE Thermistor_LUT[] = { 46000u, 45774u, 45548u, 45325u, 45102u, 44881u, 44661u, 44442u, 44224u,
 44008u, 43793u, 43579u, 43366u, 43154u, 42944u, 42735u, 42527u, 42320u, 42114u, 41910u, 41707u, 41504u, 41303u, 41103u,
 40904u, 40707u, 40510u, 40314u, 40120u, 39927u, 39734u, 39543u, 39353u, 39164u, 38976u, 38789u, 38603u, 38418u, 38234u,
 38051u, 37869u, 37688u, 37508u, 37329u, 37151u, 36974u, 36798u, 36623u, 36449u, 36276u, 36104u, 35933u, 35763u, 35593u,
 35425u, 35257u, 35091u, 34925u, 34760u, 34596u, 34433u, 34271u, 34110u, 33950u, 33790u, 33632u, 33474u, 33317u, 33161u,
 33006u, 32852u, 32698u, 32545u, 32394u, 32243u, 32092u, 31943u, 31794u, 31647u, 31500u, 31353u, 31208u, 31063u, 30919u,
 30776u, 30634u, 30492u, 30351u, 30211u, 30072u, 29934u, 29796u, 29659u, 29522u, 29387u, 29252u, 29117u, 28984u, 28851u,
 28719u, 28588u, 28457u, 28327u, 28198u, 28069u, 27941u, 27814u, 27687u, 27561u, 27436u, 27311u, 27187u, 27064u, 26941u,
 26819u, 26698u, 26577u, 26457u, 26338u, 26219u, 26101u, 25983u, 25866u, 25750u, 25634u, 25519u, 25404u, 25290u, 25177u,
 25064u, 24952u, 24840u, 24729u, 24619u, 24509u, 24399u, 24291u, 24183u, 24075u, 23968u, 23861u, 23755u, 23650u, 23545u,
 23441u, 23337u, 23233u, 23131u, 23029u, 22927u, 22826u, 22725u, 22625u, 22525u, 22426u, 22327u, 22229u, 22132u, 22035u,
 21938u, 21842u, 21746u, 21651u, 21556u, 21462u, 21368u, 21275u, 21182u, 21090u, 20998u, 20907u, 20816u, 20726u, 20636u,
 20546u, 20457u, 20368u, 20280u, 20192u, 20105u, 20018u, 19932u, 19846u, 19760u, 19675u, 19591u, 19506u, 19422u, 19339u,
 19256u, 19173u, 19091u, 19009u, 18928u, 18847u, 18766u, 18686u, 18606u, 18527u, 18448u, 18370u, 18291u, 18214u, 18136u,
 18059u, 17982u, 17906u, 17830u, 17755u, 17680u, 17605u, 17530u, 17456u, 17383u, 17309u, 17236u, 17164u, 17091u, 17020u,
 16948u, 16877u, 16806u, 16735u, 16665u, 16595u, 16526u, 16457u, 16388u, 16320u, 16251u, 16184u, 16116u, 16049u, 15982u,
 15916u, 15850u, 15784u, 15718u, 15653u, 15588u, 15524u, 15459u, 15395u, 15332u, 15268u, 15205u, 15143u, 15080u, 15018u,
 14956u, 14895u, 14833u, 14772u, 14712u, 14651u, 14591u, 14531u, 14472u, 14413u, 14354u, 14295u, 14237u, 14179u, 14121u,
 14063u, 14006u, 13949u, 13892u, 13836u, 13780u, 13724u, 13668u, 13613u, 13558u, 13503u, 13448u, 13394u, 13340u, 13286u,
 13232u, 13179u, 13126u, 13073u, 13020u, 12968u, 12916u, 12864u, 12812u, 12761u, 12710u, 12659u, 12608u, 12558u, 12508u,
 12458u, 12408u, 12359u, 12310u, 12261u, 12212u, 12163u, 12115u, 12067u, 12019u, 11971u, 11924u, 11877u, 11830u, 11783u,
 11736u, 11690u, 11644u, 11598u, 11552u, 11507u, 11461u, 11416u, 11371u, 11327u, 11282u, 11238u, 11194u, 11150u, 11106u,
 11063u, 11020u, 10977u, 10934u, 10891u, 10849u, 10806u, 10764u, 10722u, 10681u, 10639u, 10598u, 10557u, 10516u, 10475u,
 10434u, 10394u, 10354u, 10314u, 10274u, 10234u, 10195u, 10155u, 10116u, 10077u, 10039u, 10000u, 9962u, 9923u, 9885u,
 9847u, 9810u, 9772u, 9735u, 9697u, 9660u, 9623u, 9587u, 9550u, 9514u, 9477u, 9441u, 9405u, 9370u, 9334u, 9299u, 9263u,
 9228u, 9193u, 9158u, 9124u, 9089u, 9055u, 9021u, 8987u, 8953u, 8919u, 8885u, 8852u, 8819u, 8786u, 8753u, 8720u, 8687u,
 8654u, 8622u, 8590u, 8558u, 8526u, 8494u, 8462u, 8430u, 8399u, 8368u, 8336u, 8305u, 8275u, 8244u, 8213u, 8183u, 8152u,
 8122u, 8092u, 8062u, 8032u, 8002u, 7973u, 7943u, 7914u, 7885u, 7856u, 7827u, 7798u, 7769u, 7741u, 7712u, 7684u, 7656u,
 7628u, 7600u, 7572u, 7544u, 7517u, 7489u, 7462u, 7435u, 7408u, 7381u, 7354u, 7327u, 7300u, 7274u, 7247u, 7221u, 7195u,
 7169u, 7143u, 7117u, 7091u, 7065u, 7040u, 7014u, 6989u, 6964u, 6939u, 6914u, 6889u, 6864u, 6839u, 6815u, 6790u, 6766u,
 6742u, 6717u, 6693u, 6669u, 6646u, 6622u, 6598u, 6575u, 6551u, 6528u, 6504u, 6481u, 6458u, 6435u, 6412u, 6390u, 6367u,
 6344u, 6322u, 6299u, 6277u, 6255u, 6233u, 6211u, 6189u, 6167u, 6145u, 6124u, 6102u, 6080u, 6059u, 6038u, 6017u, 5995u,
 5974u, 5953u, 5933u, 5912u, 5891u, 5870u, 5850u, 5829u, 5809u, 5789u, 5769u, 5749u, 5729u, 5709u, 5689u, 5669u, 5649u,
 5630u, 5610u, 5591u, 5571u, 5552u, 5533u, 5514u, 5495u, 5476u, 5457u, 5438u, 5419u, 5400u, 5382u, 5363u, 5345u, 5326u,
 5308u, 5290u, 5272u, 5254u, 5236u, 5218u, 5200u, 5182u, 5164u, 5147u, 5129u, 5112u, 5094u, 5077u, 5060u, 5042u, 5025u,
 5008u, 4991u, 4974u, 4957u, 4941u, 4924u, 4907u, 4891u, 4874u, 4858u, 4841u, 4825u, 4808u, 4792u, 4776u, 4760u, 4744u,
 4728u, 4712u, 4696u, 4681u, 4665u, 4649u, 4634u, 4618u, 4603u, 4587u, 4572u, 4557u, 4541u, 4526u, 4511u, 4496u, 4481u,
 4466u, 4451u, 4437u, 4422u, 4407u, 4393u, 4378u, 4364u, 4349u, 4335u, 4320u, 4306u, 4292u, 4278u, 4264u, 4250u, 4236u,
 4222u, 4208u, 4194u, 4180u, 4166u, 4153u, 4139u, 4126u, 4112u };


    #if (Thermistor_IMPLEMENTATION == Thermistor_EQUATION_METHOD)

        float32 stEqn;
        float32 logrT;

        /* Calculate thermistor resistance from the voltages */
        #if(!CY_PSOC3)
            logrT = (float32)log((float64)resT);
        #else
            logrT = log((float32)resT);
        #endif  /* (!CY_PSOC3) */

        /* Calculate temperature from the resistance of thermistor using Steinhart-Hart Equation */
        #if(!CY_PSOC3)
            stEqn = (float32)(Thermistor_THA + (Thermistor_THB * logrT) + 
                             (Thermistor_THC * pow((float64)logrT, (float32)3)));
        #else
            stEqn = (float32)(Thermistor_THA + (Thermistor_THB * logrT) + 
                             (Thermistor_THC * pow(logrT, (float32)3)));
        #endif  /* (!CY_PSOC3) */

        tempTR = (int16)((float32)((((1.0 / stEqn) - Thermistor_K2C) * (float32)Thermistor_SCALE) + 0.5));

    #else /* Thermistor_IMPLEMENTATION == Thermistor_LUT_METHOD */

        uint16 mid;
        uint16 first = 0u;
        uint16 last = Thermistor_LUT_SIZE - 1u;

        /* Calculate temperature from the resistance of thermistor by using the LUT */
        while (first < last)
        {
            mid = (first + last) >> 1u;

            if ((0u == mid) || ((Thermistor_LUT_SIZE - 1u) == mid) || (resT == Thermistor_LUT[mid]))
            {
                last = mid;
                break;
            }
            else if (Thermistor_LUT[mid] > resT)
            {
                first = mid + 1u;
            }
            else /* (Thermistor_LUT[mid] < resT) */
            {
                last = mid - 1u;
            }
        }

        /* Calculation the closest entry in the LUT */
        if ((Thermistor_LUT[last] > resT) && (last < (Thermistor_LUT_SIZE - 1u)) &&
           ((Thermistor_LUT[last] - resT) > (resT - Thermistor_LUT[last + 1u])))
        {
            last++;
        }
        else if ((Thermistor_LUT[last] < resT) && (last > 0u) &&
                ((Thermistor_LUT[last - 1u] - resT) < (resT - Thermistor_LUT[last])))
        {
            last--;
        }
        else
        {
            /* Closest entry in the LUT already found */
        }

        tempTR = Thermistor_MIN_TEMP + (int16)((uint16)(last * Thermistor_ACCURACY));

    #endif /* (Thermistor_IMPLEMENTATION == Thermistor_EQUATION_METHOD) */

    return (tempTR);
}


/* [] END OF FILE */
