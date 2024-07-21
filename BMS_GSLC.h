//<File !Start!>
// FILE: [BMS_GSLC.h]
// Created by GUIslice Builder version: [0.17.b27]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XSeekbar.h"
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if !defined(DRV_DISP_TFT_ESPI)
  #error E_PROJECT_OPTIONS tab->Graphics Library should be Adafruit_GFX
#endif
#include <TFT_eSPI.h>
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_MAIN,E_PG2,E_PG3,E_PG4};
enum {E_ELEM_BTN1,E_ELEM_BTN10,E_ELEM_BTN11,E_ELEM_BTN12,E_ELEM_BTN13
      ,E_ELEM_BTN14,E_ELEM_BTN15,E_ELEM_BTN16,E_ELEM_BTN2,E_ELEM_BTN5
      ,E_ELEM_BTN6,E_ELEM_BTN9,E_ELEM_SEEKBAR2,E_ELEM_SEEKBAR3
      ,E_ELEM_SEEKBAR5,E_ELEM_SEEKBAR6,E_ELEM_TEXT1,E_ELEM_TEXT11
      ,E_ELEM_TEXT12,E_ELEM_TEXT2,E_ELEM_TEXT3,E_ELEM_TEXT5
      ,E_ELEM_TEXT6,E_ELEM_TEXT8};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN5X8,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                4

#define MAX_ELEM_PG_MAIN 5 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM
// Define the maximum number of elements per page
// - To enable the same code to run on devices that support storing
//   data into Flash (PROGMEM) and those that don't, we can make the
//   number of elements in Flash dependent upon GSLC_USE_PROGMEM
// - This should allow both Arduino and ARM Cortex to use the same code.

#define MAX_ELEM_PG2 8 // # Elems total on page
#if (GSLC_USE_PROGMEM)
  #define MAX_ELEM_PG2_PROG 2 // # Elems in Flash
#else
  #define MAX_ELEM_PG2_PROG 0 // No Elems in Flash
#endif
#define MAX_ELEM_PG2_RAM MAX_ELEM_PG2 - MAX_ELEM_PG2_PROG 

#define MAX_ELEM_PG3 2 // # Elems total on page
#define MAX_ELEM_PG3_RAM MAX_ELEM_PG3 // # Elems in RAM

#define MAX_ELEM_PG4 9 // # Elems total on page
#if (GSLC_USE_PROGMEM)
  #define MAX_ELEM_PG4_PROG 2 // # Elems in Flash
#else
  #define MAX_ELEM_PG4_PROG 0 // No Elems in Flash
#endif
#define MAX_ELEM_PG4_RAM MAX_ELEM_PG4 - MAX_ELEM_PG4_PROG 
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsElem                     m_asPage2Elem[MAX_ELEM_PG2_RAM];
gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_PG2];
gslc_tsElem                     m_asPage3Elem[MAX_ELEM_PG3_RAM];
gslc_tsElemRef                  m_asPage3ElemRef[MAX_ELEM_PG3];
gslc_tsElem                     m_asPage4Elem[MAX_ELEM_PG4_RAM];
gslc_tsElemRef                  m_asPage4ElemRef[MAX_ELEM_PG4];

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemSeekbar1_2;
extern gslc_tsElemRef* m_pElemSeekbar1_2_3;
extern gslc_tsElemRef* m_pElemSeekbar1_2_3_5;
extern gslc_tsElemRef* m_pElemSeekbar1_2_6;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN10X16,GSLC_FONTREF_PTR,NULL,2)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);
  gslc_PageAdd(&m_gui,E_PG2,m_asPage2Elem,MAX_ELEM_PG2_RAM,m_asPage2ElemRef,MAX_ELEM_PG2);
  gslc_PageAdd(&m_gui,E_PG3,m_asPage3Elem,MAX_ELEM_PG3_RAM,m_asPage3ElemRef,MAX_ELEM_PG3);
  gslc_PageAdd(&m_gui,E_PG4,m_asPage4Elem,MAX_ELEM_PG4_RAM,m_asPage4ElemRef,MAX_ELEM_PG4);

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_GREEN);

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  
  // Create E_ELEM_TEXT1 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT1,E_PG_MAIN,(gslc_tsRect){30,30,168,16},
    (char*)"GIAO DIEN HVAC",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  
  // Create E_ELEM_TEXT2 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT2,E_PG_MAIN,(gslc_tsRect){20,100,108,16},
    (char*)"Nhiet do ",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLUE);
  
  // Create E_ELEM_TEXT3 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT3,E_PG_MAIN,(gslc_tsRect){20,170,60,16},
    (char*)"Do am",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLUE);
  
  // create E_ELEM_BTN1 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN1,E_PG_MAIN,
    (gslc_tsRect){10,250,80,40},(char*)"Trang truoc ",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_BTN2 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN2,E_PG_MAIN,
    (gslc_tsRect){150,250,80,40},(char*)"Trang sau",0,E_BUILTIN5X8,&CbBtnCommon);

  // -----------------------------------
  // PAGE: E_PG2
  
  
  // Create E_ELEM_TEXT5 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT5,E_PG2,(gslc_tsRect){60,30,108,16},
    (char*)"SET POINT",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  
  // Create E_ELEM_TEXT6 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT6,E_PG2,(gslc_tsRect){10,70,84,16},
    (char*)"GIA TRI",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLUE);
  
  // create E_ELEM_BTN5 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN5,E_PG2,
    (gslc_tsRect){10,250,80,40},(char*)"Trang truoc ",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_BTN6 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN6,E_PG2,
    (gslc_tsRect){150,250,80,40},(char*)"Trang sau",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // Create E_ELEM_TEXT8 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT8,E_PG2,(gslc_tsRect){20,100,96,16},
    (char*)"Nhiet do",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED_DK4);

  // Create seekbar E_ELEM_SEEKBAR2 
  gslc_ElemXSeekbarCreate_P(&m_gui,E_ELEM_SEEKBAR2,E_PG2,20,130,200,30,
    0,50,25,4,2,8,
    GSLC_COL_BLUE,GSLC_COL_GRAY,GSLC_COL_BLUE_DK2,false,GSLC_COL_GRAY,GSLC_COL_CYAN);
  pElemRef = gslc_PageFindElemById(&m_gui,E_PG2,E_ELEM_SEEKBAR2);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  m_pElemSeekbar1_2 = pElemRef;
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,GSLC_COL_BLUE_LT4,true,GSLC_COL_GRAY,
    0,10,GSLC_COL_GRAY);
  
  // Create E_ELEM_TEXT12 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT12,E_PG2,(gslc_tsRect){20,180,60,16},
    (char*)"Do am",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED_DK4);

  // Create seekbar E_ELEM_SEEKBAR6 
  gslc_ElemXSeekbarCreate_P(&m_gui,E_ELEM_SEEKBAR6,E_PG2,20,210,200,30,
    50,100,75,4,2,8,
    GSLC_COL_BLUE,GSLC_COL_GRAY,GSLC_COL_BLUE_DK2,false,GSLC_COL_GRAY,GSLC_COL_CYAN);
  pElemRef = gslc_PageFindElemById(&m_gui,E_PG2,E_ELEM_SEEKBAR6);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  m_pElemSeekbar1_2_6 = pElemRef;
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,GSLC_COL_BLUE_LT4,true,GSLC_COL_GRAY,
    0,10,GSLC_COL_GRAY);

  // -----------------------------------
  // PAGE: E_PG3
  
  
  // create E_ELEM_BTN9 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN9,E_PG3,
    (gslc_tsRect){10,250,80,40},(char*)"Trang truoc ",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_BTN10 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN10,E_PG3,
    (gslc_tsRect){150,250,80,40},(char*)"Trang sau",0,E_BUILTIN5X8,&CbBtnCommon);

  // -----------------------------------
  // PAGE: E_PG4
  

  // Create seekbar E_ELEM_SEEKBAR3 
  gslc_ElemXSeekbarCreate_P(&m_gui,E_ELEM_SEEKBAR3,E_PG4,10,210,200,30,
    0,100,0,4,2,8,
    GSLC_COL_BLUE,GSLC_COL_GRAY,GSLC_COL_BLUE_DK2,false,GSLC_COL_GRAY,GSLC_COL_CYAN);
  pElemRef = gslc_PageFindElemById(&m_gui,E_PG4,E_ELEM_SEEKBAR3);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  m_pElemSeekbar1_2_3 = pElemRef;
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,GSLC_COL_BLUE_LT4,true,GSLC_COL_GRAY,
    0,10,GSLC_COL_GRAY);
  
  // create E_ELEM_BTN11 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN11,E_PG4,
    (gslc_tsRect){10,250,80,40},(char*)"Trang truoc ",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_BTN12 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN12,E_PG4,
    (gslc_tsRect){150,250,80,40},(char*)"Trang sau",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // Create E_ELEM_TEXT11 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT11,E_PG4,(gslc_tsRect){30,20,168,16},
    (char*)"Quat thong gio",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  
  // create E_ELEM_BTN13 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN13,E_PG4,
    (gslc_tsRect){10,70,80,40},(char*)"Bat quat 1",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_RED,GSLC_COL_RED_DK4,GSLC_COL_RED);
  
  // create E_ELEM_BTN14 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN14,E_PG4,
    (gslc_tsRect){10,160,80,40},(char*)"Bat quat 2",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_RED,GSLC_COL_RED_DK4,GSLC_COL_RED);

  // Create seekbar E_ELEM_SEEKBAR5 
  gslc_ElemXSeekbarCreate_P(&m_gui,E_ELEM_SEEKBAR5,E_PG4,10,120,200,30,
    0,100,0,4,2,8,
    GSLC_COL_BLUE,GSLC_COL_GRAY,GSLC_COL_BLUE_DK2,false,GSLC_COL_GRAY,GSLC_COL_CYAN);
  pElemRef = gslc_PageFindElemById(&m_gui,E_PG4,E_ELEM_SEEKBAR5);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  m_pElemSeekbar1_2_3_5 = pElemRef;
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,GSLC_COL_BLUE_LT4,true,GSLC_COL_GRAY,
    0,10,GSLC_COL_GRAY);
  
  // create E_ELEM_BTN15 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN15,E_PG4,
    (gslc_tsRect){150,70,80,40},(char*)"Tat quat 1",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_RED,GSLC_COL_RED_DK4,GSLC_COL_RED);
  
  // create E_ELEM_BTN16 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN16,E_PG4,
    (gslc_tsRect){150,160,80,40},(char*)"Tat quat 2",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_RED,GSLC_COL_RED_DK4,GSLC_COL_RED);
//<InitGUI !End!>

//<Startup !Start!>
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
