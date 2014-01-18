#!/sbin/sh
# Copyright (C) 2012 The Android Open Source Project
# Copyright (C) 2013-2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Allows customization for various hltenci variants.
#


CMDLINE=`cat /proc/cmdline`
mv /system/build.prop /tmp/build.prop

if [[ $CMDLINE != "${CMDLINE/SM-N900T}" ]]; #hltetmo
    then
       sed -i 's|ro.build.fingerprint=xxxxxxxxxx|ro.build.fingerprint=samsung/hltetmo/hltetmo:4.3/JSS15J/N900TUVUBMI7:user/release-keys|g' /tmp/build.prop
       sed -i 's|ro.build.description=xxxxxxxxxx|hltetmo-user 4.3 JSS15J N900TUVUBMI7 release-keys|g' /tmp/build.prop
       sed -i 's|ro.product.model=hlte|ro.product.model=SM-N900T|g' /tmp/build.prop
       sed -i 's|ro.product.device=hlte|ro.product.device=hltetmo|g' /tmp/build.prop
       sed -i 's|ro.cm.device=hlte|ro.cm.device=hltetmo|g' /tmp/build.prop

elif [[ $CMDLINE != "${CMDLINE/SM-N9005W8}" ]]; #hltexx
    then
       sed -i 's|ro.build.fingerprint=xxxxxxxxxx|ro.build.fingerprint=samsung/hltevl/hltecan:4.3/JSS15J/N900W8VLUBMJ4:user/release-keys|g' /tmp/build.prop
       sed -i 's|ro.build.description=xxxxxxxxxx|ro.build.description="hltevl-user 4.3 JSS15J N900W8VLUBMJ4 release-keys" release-keys|g' /tmp/build.prop
       sed -i 's|ro.product.model=hlte|ro.product.model=SM-N900W8|g' /tmp/build.prop
        sed -i 's|ro.product.device=hlte|ro.product.device=hltecan|g' /tmp/build.prop
       sed -i 's|ro.cm.device=hlte|ro.cm.device=hltecan|g' /tmp/build.prop

fi

mv /tmp/build.prop /system/build.prop
chmod 644 /system/build.prop
