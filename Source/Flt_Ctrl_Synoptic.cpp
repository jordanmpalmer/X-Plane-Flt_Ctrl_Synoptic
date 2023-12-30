
// Xcode X-Plane Plugin Boilerplate
// Published by Jordan Palmer

#define XPLM200 = 1;
#define XPLM210 = 1
#define XPLM300 = 1;  // requires SDK3.0

#include "XPLMPlugin.h"
#include "XPLMDisplay.h"
#include "XPLMGraphics.h"
#include "XPLMProcessing.h"
#include "XPLMDataAccess.h"
#include "XPLMMenus.h"
#include "XPLMUtilities.h"
#include "XPWidgets.h"
#include "XPStandardWidgets.h"
#include "XPLMScenery.h"

#include <string.h>
#include <math.h>

#define MSG_ADD_DATAREF 0x01000000           //  Add dataref to DRE message

// reference for dataref
XPLMDataRef aileron1_deg_dataref = NULL;
XPLMDataRef aileron2_deg_dataref = NULL;
XPLMDataRef elevator1_deg_dataref = NULL;
XPLMDataRef elevator2_deg_dataref = NULL;
XPLMDataRef rudder1_deg_dataref = NULL;
XPLMDataRef rudder2_deg_dataref = NULL;



// give dataref a variable
int     aileron1_deg;
int     aileron2_deg;
int     elevator1_deg;
int     elevator2_deg;
int     rudder1_deg;
int     rudder2_deg;


PLUGIN_API int XPluginStart(
    char *        outName,
    char *        outSig,
    char *        outDesc)
{
    // Plugin Info for XP
    strcpy(outName, "Flight controls synoptic page" );
    strcpy(outSig, "JordanPalmer.787plugins.flt_ctrl_synoptic" );
    strcpy(outDesc, "Flight control synoptic page" );
    
    // bring in datarefs from XP
    aileron1_deg_dataref = XPLMFindDataRef( "sim/flightmodel2/wing/aileron1_deg" );
    aileron1_deg = XPLMGetDataf( aileron1_deg_dataref );
    aileron2_deg_dataref = XPLMFindDataRef( "sim/flightmodel2/wing/aileron2_deg" );
    aileron2_deg = XPLMGetDataf( aileron2_deg_dataref );
    
    elevator1_deg_dataref = XPLMFindDataRef( "sim/flightmodel2/wing/elevator1_deg" );
    elevator1_deg = XPLMGetDataf( elevator1_deg_dataref );
    elevator2_deg_dataref = XPLMFindDataRef( "sim/flightmodel2/wing/elevator2_deg" );
    elevator2_deg = XPLMGetDataf( elevator2_deg_dataref );
    
    rudder1_deg_dataref = XPLMFindDataRef( "sim/flightmodel2/wing/rudder1_deg" );
    rudder1_deg = XPLMGetDataf( rudder1_deg_dataref );
    rudder2_deg_dataref = XPLMFindDataRef( "sim/flightmodel2/wing/rudder2_deg" );
    rudder2_deg = XPLMGetDataf( rudder2_deg_dataref );
                             
    
    return 1;
}


PLUGIN_API void     XPluginStop(void)
{

}

PLUGIN_API void XPluginDisable(void)
{
    
}
 
PLUGIN_API int XPluginEnable(void)
{
    return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID    inFromWho,
                                     long             inMessage,
                                     void *           inParam)
{
    
}
