$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

$(call inherit-product, device/samsung/hltetmo/full_hltetmo.mk)

PRODUCT_DEVICE := hltetmo
PRODUCT_NAME := cm_hltetmo
