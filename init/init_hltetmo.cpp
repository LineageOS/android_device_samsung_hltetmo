/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2018, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_msm8974.h"

using android::base::GetProperty;
using android::init::property_set;

void set_rild_libpath(char const *variant)
{
    std::string libpath("/system/vendor/lib/libsec-ril.");
    libpath += variant;
    libpath += ".so";

    property_override("rild.libpath", libpath.c_str());
}

void cdma_properties(char const *operator_alpha,
        char const *operator_numeric,
        char const *default_network,
        char const *cdma_sub,
        char const *rild_lib_variant)
{
    /* Dynamic CDMA Properties */
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.telephony.default_network", default_network);
    property_set("ro.telephony.default_cdma_sub", cdma_sub);
    set_rild_libpath(rild_lib_variant);

    /* Static CDMA Properties */
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void gsm_properties(char const *rild_lib_variant)
{
    set_rild_libpath(rild_lib_variant);

    property_set("ro.telephony.default_network", "9");
    property_set("telephony.lteOnGsmDevice", "1");
}

void init_target_properties()
{
    std::string platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("N900R4") == 0) {
        /* hlteusc */
        property_override("ro.build.fingerprint", "samsung/hlteusc/hlteusc:5.0/LRX21V/N900R4TYUDPE2:user/release-keys");
        property_override("ro.build.description", "hlteusc-user 5.0 LRX21V N900R4TYUDPE2 release-keys");
        property_override("ro.product.model", "SM-N900R4");
        property_override("ro.product.device", "hlteusc");
        cdma_properties("U.S. Cellular", "311220", "10", "0", "usc");
    } else if (bootloader.find("N900T") == 0) {
        /* hltetmo */
        property_override("ro.build.fingerprint", "samsung/hltetmo/hltetmo:5.0/LRX21V/N900TUVUFQD2:user/release-keys");
        property_override("ro.build.description", "hltetmo-user 5.0 LRX21V N900TUVUFQD2 release-keys");
        property_override("ro.product.model", "SM-N900T");
        property_override("ro.product.device", "hltetmo");
        gsm_properties("tmo");
    } else if (bootloader.find("N900V") == 0) {
        /* hltevzw */
        property_override("ro.build.fingerprint", "Verizon/hltevzw/hltevzw:5.0/LRX21V/N900VVRSEPL1:user/release-keys");
        property_override("ro.build.description", "hltevzw-user 5.0 LRX21V N900VVRSEPL1 release-keys");
        property_override("ro.product.model", "SM-N900V");
        property_override("ro.product.device", "hltevzw");
        cdma_properties("Verizon", "311480", "10", "1", "vzw");
    } else if (bootloader.find("N900W8") == 0) {
        /* hltecan */
        property_override("ro.build.fingerprint", "samsung/hltevl/hltecan:5.0/LRX21V/N900W8VLU2DPG1:user/release-keys");
        property_override("ro.build.description", "hltevl-user 5.0 LRX21V N900W8VLU2DPG1 release-keys");
        property_override("ro.product.model", "SM-N900W8");
        property_override("ro.product.device", "hltecan");
        gsm_properties("can");
    } else {
        gsm_properties("tmo");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
