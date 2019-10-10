/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

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

#include "init_msm8974.h"

using android::base::GetProperty;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("N900R4") == 0) {
        /* hlteusc */
        property_override("ro.build.description", "hlteusc-user 5.0 LRX21V N900R4TYUDPE2 release-keys");
        set_ro_product_prop("device", "hlteusc");
        set_ro_product_prop("fingerprint", "samsung/hlteusc/hlteusc:5.0/LRX21V/N900R4TYUDPE2:user/release-keys");
        set_ro_product_prop("model", "SM-N900R4");
        set_ro_product_prop("name", "hlteusc");
        cdma_properties("U.S. Cellular", "311220", "0", "10", "usc");
    } else if (bootloader.find("N900T") == 0) {
        /* hltetmo */
        property_override("ro.build.description", "hltetmo-user 5.0 LRX21V N900TUVUFQD2 release-keys");
        set_ro_product_prop("device", "hltetmo");
        set_ro_product_prop("fingerprint", "samsung/hltetmo/hltetmo:5.0/LRX21V/N900TUVUFQD2:user/release-keys");
        set_ro_product_prop("model", "SM-N900T");
        set_ro_product_prop("name", "hltetmo");
        gsm_properties("9", "tmo");
    } else if (bootloader.find("N900V") == 0) {
        /* hltevzw */
        property_override("ro.build.description", "hltevzw-user 5.0 LRX21V N900VVRSEPL1 release-keys");
        set_ro_product_prop("device", "hltevzw");
        set_ro_product_prop("fingerprint", "Verizon/hltevzw/hltevzw:5.0/LRX21V/N900VVRSEPL1:user/release-keys");
        set_ro_product_prop("model", "SM-N900V");
        set_ro_product_prop("name", "hltevzw");
        cdma_properties("Verizon", "311480", "1", "10", "vzw");
    } else if (bootloader.find("N900W8") == 0) {
        /* hltecan */
        property_override("ro.build.description", "hltevl-user 5.0 LRX21V N900W8VLU2DPG1 release-keys");
        set_ro_product_prop("device", "hltecan");
        set_ro_product_prop("fingerprint", "samsung/hltevl/hltecan:5.0/LRX21V/N900W8VLU2DPG1:user/release-keys");
        set_ro_product_prop("model", "SM-N900W8");
        set_ro_product_prop("name", "hltecan");
        gsm_properties("9", "can");
    } else {
        gsm_properties("9", "tmo");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
