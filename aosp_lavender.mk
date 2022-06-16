#
# Copyright (C) 2019 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit vendor
$(call inherit-product, vendor/aosp/common.mk)

# Inherit from lavender device
$(call inherit-product, $(LOCAL_PATH)/device.mk)
$(call inherit-product, $(LOCAL_PATH)/device-hidl.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := aosp_lavender
PRODUCT_DEVICE := lavender
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := Redmi Note 7
PRODUCT_MANUFACTURER := Xiaomi
PRODUCT_GMS_CLIENTID_BASE := android-xiaomi

PRODUCT_BUILD_PROP_OVERRIDES += \
    TARGET_DEVICE="lavender" \
    PRODUCT_NAME="lavender"

###-------Arcana------###

# Me
ARCANA_MAINTAINER := Mayur

# Quick tap feature
TARGET_SUPPORTS_QUICK_TAP := true

# Face Unlock
TARGET_FACE_UNLOCK_SUPPORTED := true

# Bloom and Living Universe Pixel Wallpapers
TARGET_INCLUDE_LIVE_WALLPAPERS := true

# Pixel Now playing feature
TARGET_SUPPORTS_NOW_PLAYING := true

# GAPPS
WITH_GAPPS := true # fuck vanilla users [laughs in demonic way]
