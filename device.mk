#
# Copyright (C) 2014 The CyanogenMod Project
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

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Get non-open-source specific aspects
$(call inherit-product-if-exists, vendor/samsung/hltetmo/hltetmo-vendor.mk)

# NFC
PRODUCT_PACKAGES += \
    libpn547_fw \
    nfc_nci.pn54x.default

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/security_nfc_profile.dat:system/etc/security_nfc_profile.dat \
    $(LOCAL_PATH)/configs/libnfc-brcm.conf:system/etc/libnfc-brcm.conf \
    $(LOCAL_PATH)/configs/libnfc-nxp.conf:system/etc/libnfc-nxp.conf

# Overlays
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

# Variant blobs script
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/releasetools/variant_blobs_hook.sh:install/bin/variant_blobs_hook.sh \
    device/samsung/hlte-common/releasetools/variant_blobs.sh:install/bin/variant_blobs.sh

# Common hlte
$(call inherit-product, device/samsung/hlte-common/hlte.mk)
