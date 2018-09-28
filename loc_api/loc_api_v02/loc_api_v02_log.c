/* Copyright (c) 2011-2015, 2018, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation, nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <loc_api_v02_log.h>
#include <location_service_v02.h>

static const loc_name_val_s_type loc_v02_event_name[] =
{
    NAME_VAL(QMI_LOC_GET_SUPPORTED_MSGS_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SUPPORTED_MSGS_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SUPPORTED_FIELDS_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SUPPORTED_FIELDS_RESP_V02),
    NAME_VAL(QMI_LOC_INFORM_CLIENT_REVISION_REQ_V02),
    NAME_VAL(QMI_LOC_INFORM_CLIENT_REVISION_RESP_V02),
    NAME_VAL(QMI_LOC_REG_EVENTS_REQ_V02),
    NAME_VAL(QMI_LOC_REG_EVENTS_RESP_V02),
    NAME_VAL(QMI_LOC_START_REQ_V02),
    NAME_VAL(QMI_LOC_START_RESP_V02),
    NAME_VAL(QMI_LOC_STOP_REQ_V02),
    NAME_VAL(QMI_LOC_STOP_RESP_V02),
    NAME_VAL(QMI_LOC_EVENT_POSITION_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GNSS_SV_INFO_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_NMEA_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_NI_NOTIFY_VERIFY_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_INJECT_TIME_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_INJECT_PREDICTED_ORBITS_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_INJECT_POSITION_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_ENGINE_STATE_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_FIX_SESSION_STATE_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_WIFI_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_SENSOR_STREAMING_READY_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_TIME_SYNC_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_SET_SPI_STREAMING_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_LOCATION_SERVER_CONNECTION_REQ_IND_V02),
    NAME_VAL(QMI_LOC_GET_SERVICE_REVISION_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SERVICE_REVISION_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SERVICE_REVISION_IND_V02),
    NAME_VAL(QMI_LOC_GET_FIX_CRITERIA_REQ_V02),
    NAME_VAL(QMI_LOC_GET_FIX_CRITERIA_RESP_V02),
    NAME_VAL(QMI_LOC_GET_FIX_CRITERIA_IND_V02),
    NAME_VAL(QMI_LOC_NI_USER_RESPONSE_REQ_V02),
    NAME_VAL(QMI_LOC_NI_USER_RESPONSE_RESP_V02),
    NAME_VAL(QMI_LOC_NI_USER_RESPONSE_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_PREDICTED_ORBITS_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_PREDICTED_ORBITS_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_PREDICTED_ORBITS_DATA_IND_V02),
    NAME_VAL(QMI_LOC_GET_PREDICTED_ORBITS_DATA_SOURCE_REQ_V02),
    NAME_VAL(QMI_LOC_GET_PREDICTED_ORBITS_DATA_SOURCE_RESP_V02),
    NAME_VAL(QMI_LOC_GET_PREDICTED_ORBITS_DATA_SOURCE_IND_V02),
    NAME_VAL(QMI_LOC_GET_PREDICTED_ORBITS_DATA_VALIDITY_REQ_V02),
    NAME_VAL(QMI_LOC_GET_PREDICTED_ORBITS_DATA_VALIDITY_RESP_V02),
    NAME_VAL(QMI_LOC_GET_PREDICTED_ORBITS_DATA_VALIDITY_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_UTC_TIME_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_UTC_TIME_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_UTC_TIME_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_POSITION_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_POSITION_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_POSITION_IND_V02),
    NAME_VAL(QMI_LOC_SET_ENGINE_LOCK_REQ_V02),
    NAME_VAL(QMI_LOC_SET_ENGINE_LOCK_RESP_V02),
    NAME_VAL(QMI_LOC_SET_ENGINE_LOCK_IND_V02),
    NAME_VAL(QMI_LOC_GET_ENGINE_LOCK_REQ_V02),
    NAME_VAL(QMI_LOC_GET_ENGINE_LOCK_RESP_V02),
    NAME_VAL(QMI_LOC_GET_ENGINE_LOCK_IND_V02),
    NAME_VAL(QMI_LOC_SET_SBAS_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_SET_SBAS_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_SBAS_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_GET_SBAS_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SBAS_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SBAS_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_SET_NMEA_TYPES_REQ_V02),
    NAME_VAL(QMI_LOC_SET_NMEA_TYPES_RESP_V02),
    NAME_VAL(QMI_LOC_SET_NMEA_TYPES_IND_V02),
    NAME_VAL(QMI_LOC_GET_NMEA_TYPES_REQ_V02),
    NAME_VAL(QMI_LOC_GET_NMEA_TYPES_RESP_V02),
    NAME_VAL(QMI_LOC_GET_NMEA_TYPES_IND_V02),
    NAME_VAL(QMI_LOC_SET_LOW_POWER_MODE_REQ_V02),
    NAME_VAL(QMI_LOC_SET_LOW_POWER_MODE_RESP_V02),
    NAME_VAL(QMI_LOC_SET_LOW_POWER_MODE_IND_V02),
    NAME_VAL(QMI_LOC_GET_LOW_POWER_MODE_REQ_V02),
    NAME_VAL(QMI_LOC_GET_LOW_POWER_MODE_RESP_V02),
    NAME_VAL(QMI_LOC_GET_LOW_POWER_MODE_IND_V02),
    NAME_VAL(QMI_LOC_REGISTER_MASTER_CLIENT_REQ_V02),
    NAME_VAL(QMI_LOC_REGISTER_MASTER_CLIENT_RESP_V02),
    NAME_VAL(QMI_LOC_REGISTER_MASTER_CLIENT_IND_V02),
    NAME_VAL(QMI_LOC_SET_SERVER_REQ_V02),
    NAME_VAL(QMI_LOC_SET_SERVER_RESP_V02),
    NAME_VAL(QMI_LOC_SET_SERVER_IND_V02),
    NAME_VAL(QMI_LOC_GET_SERVER_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SERVER_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SERVER_IND_V02),
    NAME_VAL(QMI_LOC_DELETE_ASSIST_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_DELETE_ASSIST_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_DELETE_ASSIST_DATA_IND_V02),
    NAME_VAL(QMI_LOC_SET_XTRA_T_SESSION_CONTROL_REQ_V02),
    NAME_VAL(QMI_LOC_SET_XTRA_T_SESSION_CONTROL_RESP_V02),
    NAME_VAL(QMI_LOC_SET_XTRA_T_SESSION_CONTROL_IND_V02),
    NAME_VAL(QMI_LOC_GET_XTRA_T_SESSION_CONTROL_REQ_V02),
    NAME_VAL(QMI_LOC_GET_XTRA_T_SESSION_CONTROL_RESP_V02),
    NAME_VAL(QMI_LOC_GET_XTRA_T_SESSION_CONTROL_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_WIFI_POSITION_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_WIFI_POSITION_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_WIFI_POSITION_IND_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_GET_REGISTERED_EVENTS_REQ_V02),
    NAME_VAL(QMI_LOC_GET_REGISTERED_EVENTS_RESP_V02),
    NAME_VAL(QMI_LOC_GET_REGISTERED_EVENTS_IND_V02),
    NAME_VAL(QMI_LOC_SET_OPERATION_MODE_REQ_V02),
    NAME_VAL(QMI_LOC_SET_OPERATION_MODE_RESP_V02),
    NAME_VAL(QMI_LOC_SET_OPERATION_MODE_IND_V02),
    NAME_VAL(QMI_LOC_GET_OPERATION_MODE_REQ_V02),
    NAME_VAL(QMI_LOC_GET_OPERATION_MODE_RESP_V02),
    NAME_VAL(QMI_LOC_GET_OPERATION_MODE_IND_V02),
    NAME_VAL(QMI_LOC_SET_SPI_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_SET_SPI_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_SET_SPI_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_SENSOR_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_SENSOR_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_SENSOR_DATA_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_TIME_SYNC_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_TIME_SYNC_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_TIME_SYNC_DATA_IND_V02),
    NAME_VAL(QMI_LOC_SET_CRADLE_MOUNT_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_SET_CRADLE_MOUNT_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_CRADLE_MOUNT_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_GET_CRADLE_MOUNT_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_GET_CRADLE_MOUNT_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_GET_CRADLE_MOUNT_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_SET_EXTERNAL_POWER_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_SET_EXTERNAL_POWER_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_EXTERNAL_POWER_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_GET_EXTERNAL_POWER_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_GET_EXTERNAL_POWER_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_GET_EXTERNAL_POWER_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_INFORM_LOCATION_SERVER_CONN_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_INFORM_LOCATION_SERVER_CONN_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_INFORM_LOCATION_SERVER_CONN_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_SET_PROTOCOL_CONFIG_PARAMETERS_REQ_V02),
    NAME_VAL(QMI_LOC_SET_PROTOCOL_CONFIG_PARAMETERS_RESP_V02),
    NAME_VAL(QMI_LOC_SET_PROTOCOL_CONFIG_PARAMETERS_IND_V02),
    NAME_VAL(QMI_LOC_GET_PROTOCOL_CONFIG_PARAMETERS_REQ_V02),
    NAME_VAL(QMI_LOC_GET_PROTOCOL_CONFIG_PARAMETERS_RESP_V02),
    NAME_VAL(QMI_LOC_GET_PROTOCOL_CONFIG_PARAMETERS_IND_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_CONTROL_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_CONTROL_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_CONTROL_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_CONTROL_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_CONTROL_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_CONTROL_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_PROPERTIES_REQ_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_PROPERTIES_RESP_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_PROPERTIES_IND_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_PROPERTIES_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_PROPERTIES_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_PROPERTIES_IND_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_PERFORMANCE_CONTROL_CONFIGURATION_REQ_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_PERFORMANCE_CONTROL_CONFIGURATION_RESP_V02),
    NAME_VAL(QMI_LOC_SET_SENSOR_PERFORMANCE_CONTROL_CONFIGURATION_IND_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_PERFORMANCE_CONTROL_CONFIGURATION_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_PERFORMANCE_CONTROL_CONFIGURATION_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SENSOR_PERFORMANCE_CONTROL_CONFIGURATION_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_SUPL_CERTIFICATE_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_SUPL_CERTIFICATE_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_SUPL_CERTIFICATE_IND_V02),
    NAME_VAL(QMI_LOC_DELETE_SUPL_CERTIFICATE_REQ_V02),
    NAME_VAL(QMI_LOC_DELETE_SUPL_CERTIFICATE_RESP_V02),
    NAME_VAL(QMI_LOC_DELETE_SUPL_CERTIFICATE_IND_V02),
    NAME_VAL(QMI_LOC_SET_POSITION_ENGINE_CONFIG_PARAMETERS_REQ_V02),
    NAME_VAL(QMI_LOC_SET_POSITION_ENGINE_CONFIG_PARAMETERS_RESP_V02),
    NAME_VAL(QMI_LOC_SET_POSITION_ENGINE_CONFIG_PARAMETERS_IND_V02),
    NAME_VAL(QMI_LOC_GET_POSITION_ENGINE_CONFIG_PARAMETERS_REQ_V02),
    NAME_VAL(QMI_LOC_GET_POSITION_ENGINE_CONFIG_PARAMETERS_RESP_V02),
    NAME_VAL(QMI_LOC_GET_POSITION_ENGINE_CONFIG_PARAMETERS_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_NI_GEOFENCE_NOTIFICATION_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GEOFENCE_GEN_ALERT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GEOFENCE_BREACH_NOTIFICATION_IND_V02),
    NAME_VAL(QMI_LOC_ADD_CIRCULAR_GEOFENCE_REQ_V02),
    NAME_VAL(QMI_LOC_ADD_CIRCULAR_GEOFENCE_RESP_V02),
    NAME_VAL(QMI_LOC_ADD_CIRCULAR_GEOFENCE_IND_V02),
    NAME_VAL(QMI_LOC_DELETE_GEOFENCE_REQ_V02),
    NAME_VAL(QMI_LOC_DELETE_GEOFENCE_RESP_V02),
    NAME_VAL(QMI_LOC_DELETE_GEOFENCE_IND_V02),
    NAME_VAL(QMI_LOC_QUERY_GEOFENCE_REQ_V02),
    NAME_VAL(QMI_LOC_QUERY_GEOFENCE_RESP_V02),
    NAME_VAL(QMI_LOC_QUERY_GEOFENCE_IND_V02),
    NAME_VAL(QMI_LOC_EDIT_GEOFENCE_REQ_V02),
    NAME_VAL(QMI_LOC_EDIT_GEOFENCE_RESP_V02),
    NAME_VAL(QMI_LOC_EDIT_GEOFENCE_IND_V02),
    NAME_VAL(QMI_LOC_GET_BEST_AVAILABLE_POSITION_REQ_V02),
    NAME_VAL(QMI_LOC_GET_BEST_AVAILABLE_POSITION_RESP_V02),
    NAME_VAL(QMI_LOC_GET_BEST_AVAILABLE_POSITION_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_MOTION_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_MOTION_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_MOTION_DATA_IND_V02),
    NAME_VAL(QMI_LOC_GET_NI_GEOFENCE_ID_LIST_REQ_V02),
    NAME_VAL(QMI_LOC_GET_NI_GEOFENCE_ID_LIST_RESP_V02),
    NAME_VAL(QMI_LOC_GET_NI_GEOFENCE_ID_LIST_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_GSM_CELL_INFO_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_GSM_CELL_INFO_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_GSM_CELL_INFO_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_NETWORK_INITIATED_MESSAGE_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_NETWORK_INITIATED_MESSAGE_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_NETWORK_INITIATED_MESSAGE_IND_V02),
    NAME_VAL(QMI_LOC_WWAN_OUT_OF_SERVICE_NOTIFICATION_REQ_V02),
    NAME_VAL(QMI_LOC_WWAN_OUT_OF_SERVICE_NOTIFICATION_RESP_V02),
    NAME_VAL(QMI_LOC_WWAN_OUT_OF_SERVICE_NOTIFICATION_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_PEDOMETER_CONTROL_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_MOTION_DATA_CONTROL_IND_V02),
    NAME_VAL(QMI_LOC_PEDOMETER_REPORT_REQ_V02),
    NAME_VAL(QMI_LOC_PEDOMETER_REPORT_RESP_V02),
    NAME_VAL(QMI_LOC_PEDOMETER_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_WCDMA_CELL_INFO_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_WCDMA_CELL_INFO_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_WCDMA_CELL_INFO_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_TDSCDMA_CELL_INFO_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_TDSCDMA_CELL_INFO_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_TDSCDMA_CELL_INFO_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_SUBSCRIBER_ID_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_SUBSCRIBER_ID_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_SUBSCRIBER_ID_IND_V02),
    NAME_VAL(QMI_LOC_SET_GEOFENCE_ENGINE_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_SET_GEOFENCE_ENGINE_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_GEOFENCE_ENGINE_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_GET_GEOFENCE_ENGINE_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_GET_GEOFENCE_ENGINE_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_GET_GEOFENCE_ENGINE_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_GET_BATCH_SIZE_REQ_V02),
    NAME_VAL(QMI_LOC_GET_BATCH_SIZE_RESP_V02),
    NAME_VAL(QMI_LOC_GET_BATCH_SIZE_IND_V02),
    NAME_VAL(QMI_LOC_START_BATCHING_REQ_V02),
    NAME_VAL(QMI_LOC_START_BATCHING_RESP_V02),
    NAME_VAL(QMI_LOC_START_BATCHING_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_BATCH_FULL_NOTIFICATION_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_LIVE_BATCHED_POSITION_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_READ_FROM_BATCH_REQ_V02),
    NAME_VAL(QMI_LOC_READ_FROM_BATCH_RESP_V02),
    NAME_VAL(QMI_LOC_READ_FROM_BATCH_IND_V02),
    NAME_VAL(QMI_LOC_STOP_BATCHING_REQ_V02),
    NAME_VAL(QMI_LOC_STOP_BATCHING_RESP_V02),
    NAME_VAL(QMI_LOC_STOP_BATCHING_IND_V02),
    NAME_VAL(QMI_LOC_RELEASE_BATCH_REQ_V02),
    NAME_VAL(QMI_LOC_RELEASE_BATCH_RESP_V02),
    NAME_VAL(QMI_LOC_RELEASE_BATCH_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_INJECT_WIFI_AP_DATA_REQ_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_WIFI_AP_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_WIFI_AP_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_WIFI_AP_DATA_IND_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_ATTACHMENT_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_ATTACHMENT_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_ATTACHMENT_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_ENABLED_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_ENABLED_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_NOTIFY_WIFI_ENABLED_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GEOFENCE_BATCHED_BREACH_NOTIFICATION_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_VEHICLE_DATA_READY_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_VEHICLE_SENSOR_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_VEHICLE_SENSOR_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_VEHICLE_SENSOR_DATA_IND_V02),
    NAME_VAL(QMI_LOC_GET_AVAILABLE_WWAN_POSITION_REQ_V02),
    NAME_VAL(QMI_LOC_GET_AVAILABLE_WWAN_POSITION_RESP_V02),
    NAME_VAL(QMI_LOC_GET_AVAILABLE_WWAN_POSITION_IND_V02),
    NAME_VAL(QMI_LOC_SET_PREMIUM_SERVICES_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_SET_PREMIUM_SERVICES_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_PREMIUM_SERVICES_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_SET_XTRA_VERSION_CHECK_REQ_V02),
    NAME_VAL(QMI_LOC_SET_XTRA_VERSION_CHECK_RESP_V02),
    NAME_VAL(QMI_LOC_SET_XTRA_VERSION_CHECK_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GNSS_MEASUREMENT_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_SV_POLYNOMIAL_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_SET_GNSS_CONSTELL_REPORT_CONFIG_V02),
    NAME_VAL(QMI_LOC_SET_GNSS_CONSTELL_REPORT_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_GNSS_CONSTELL_REPORT_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_ADD_GEOFENCE_CONTEXT_REQ_V02),
    NAME_VAL(QMI_LOC_ADD_GEOFENCE_CONTEXT_RESP_V02),
    NAME_VAL(QMI_LOC_ADD_GEOFENCE_CONTEXT_IND_V02),
    NAME_VAL(QMI_LOC_SET_GEOFENCE_ENGINE_CONTEXT_REQ_V02),
    NAME_VAL(QMI_LOC_SET_GEOFENCE_ENGINE_CONTEXT_RESP_V02),
    NAME_VAL(QMI_LOC_SET_GEOFENCE_ENGINE_CONTEXT_IND_V02),
    NAME_VAL(QMI_LOC_DELETE_GEOFENCE_CONTEXT_REQ_V02),
    NAME_VAL(QMI_LOC_DELETE_GEOFENCE_CONTEXT_RESP_V02),
    NAME_VAL(QMI_LOC_DELETE_GEOFENCE_CONTEXT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GEOFENCE_PROXIMITY_NOTIFICATION_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_GTP_CLIENT_DOWNLOADED_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_GTP_CLIENT_DOWNLOADED_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_GTP_CLIENT_DOWNLOADED_DATA_IND_V02),
    NAME_VAL(QMI_LOC_GDT_UPLOAD_BEGIN_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_GDT_UPLOAD_BEGIN_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_GDT_UPLOAD_BEGIN_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_GDT_UPLOAD_END_REQ_V02),
    NAME_VAL(QMI_LOC_GDT_UPLOAD_END_RESP_V02),
    NAME_VAL(QMI_LOC_GDT_UPLOAD_END_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GDT_UPLOAD_BEGIN_STATUS_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GDT_UPLOAD_END_REQ_IND_V02),
    NAME_VAL(QMI_LOC_START_DBT_REQ_V02),
    NAME_VAL(QMI_LOC_START_DBT_RESP_V02),
    NAME_VAL(QMI_LOC_START_DBT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_DBT_POSITION_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_DBT_SESSION_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_STOP_DBT_REQ_V02),
    NAME_VAL(QMI_LOC_STOP_DBT_RESP_V02),
    NAME_VAL(QMI_LOC_STOP_DBT_IND_V02),
    NAME_VAL(QMI_LOC_SECURE_GET_AVAILABLE_POSITION_REQ_V02),
    NAME_VAL(QMI_LOC_SECURE_GET_AVAILABLE_POSITION_RESP_V02),
    NAME_VAL(QMI_LOC_SECURE_GET_AVAILABLE_POSITION_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GEOFENCE_BATCHED_DWELL_NOTIFICATION_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GET_TIME_ZONE_INFO_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_TIME_ZONE_INFO_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_TIME_ZONE_INFO_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_TIME_ZONE_INFO_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_APCACHE_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_APCACHE_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_APCACHE_DATA_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_APDONOTCACHE_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_APDONOTCACHE_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_APDONOTCACHE_DATA_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_BATCHING_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_QUERY_AON_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_QUERY_AON_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_QUERY_AON_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_GTP_AP_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_GTP_AP_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_GTP_AP_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_BEGIN_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_BEGIN_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_BEGIN_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_READY_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_READY_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_READY_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_GDT_RECEIVE_DONE_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_GDT_RECEIVE_DONE_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_GDT_RECEIVE_DONE_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_END_STATUS_REQ_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_END_STATUS_RESP_V02),
    NAME_VAL(QMI_LOC_GDT_DOWNLOAD_END_STATUS_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GDT_DOWNLOAD_BEGIN_REQ_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GDT_RECEIVE_DONE_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_GDT_DOWNLOAD_END_REQ_IND_V02),
    NAME_VAL(QMI_LOC_DELETE_GNSS_SERVICE_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_DELETE_GNSS_SERVICE_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_DELETE_GNSS_SERVICE_DATA_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_XTRA_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_XTRA_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_XTRA_DATA_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_XTRA_PCID_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_XTRA_PCID_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_XTRA_PCID_IND_V02),
    NAME_VAL(QMI_LOC_GET_SUPPORTED_FEATURE_REQ_V02),
    NAME_VAL(QMI_LOC_GET_SUPPORTED_FEATURE_RESP_V02),
    NAME_VAL(QMI_LOC_GET_SUPPORTED_FEATURE_IND_V02),
    NAME_VAL(QMI_LOC_SET_INTERNAL_STATUS_CONFIG_REQ_V02),
    NAME_VAL(QMI_LOC_SET_INTERNAL_STATUS_CONFIG_RESP_V02),
    NAME_VAL(QMI_LOC_SET_INTERNAL_STATUS_CONFIG_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_INTERNAL_STATUS_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_INJECT_SRN_AP_DATA_REQ_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_SRN_AP_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_SRN_AP_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_SRN_AP_DATA_IND_V02),
    NAME_VAL(QMI_LOC_CROWDSOURCE_MANAGER_CONTROL_REQ_V02),
    NAME_VAL(QMI_LOC_CROWDSOURCE_MANAGER_CONTROL_RESP_V02),
    NAME_VAL(QMI_LOC_CROWDSOURCE_MANAGER_CONTROL_IND_V02),
    NAME_VAL(QMI_LOC_CROWDSOURCE_MANAGER_READ_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_CROWDSOURCE_MANAGER_READ_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_QUERY_XTRA_INFO_REQ_V02),
    NAME_VAL(QMI_LOC_QUERY_XTRA_INFO_RESP_V02),
    NAME_VAL(QMI_LOC_QUERY_XTRA_INFO_IND_V02),
    NAME_VAL(QMI_LOC_START_OUTDOOR_TRIP_BATCHING_REQ_V02),
    NAME_VAL(QMI_LOC_START_OUTDOOR_TRIP_BATCHING_RESP_V02),
    NAME_VAL(QMI_LOC_START_OUTDOOR_TRIP_BATCHING_IND_V02),
    NAME_VAL(QMI_LOC_QUERY_OTB_ACCUMULATED_DISTANCE_REQ_V02),
    NAME_VAL(QMI_LOC_QUERY_OTB_ACCUMULATED_DISTANCE_RESP_V02),
    NAME_VAL(QMI_LOC_QUERY_OTB_ACCUMULATED_DISTANCE_IND_V02),
    NAME_VAL(QMI_LOC_GET_FDCL_BS_LIST_REQ_V02),
    NAME_VAL(QMI_LOC_GET_FDCL_BS_LIST_RESP_V02),
    NAME_VAL(QMI_LOC_GET_FDCL_BS_LIST_IND_V02),
    NAME_VAL(QMI_LOC_INJECT_FDCL_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_INJECT_FDCL_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_INJECT_FDCL_DATA_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_FDCL_SERVICE_REQ_IND_V02),
    NAME_VAL(QMI_LOC_SET_BLACKLIST_SV_REQ_V02),
    NAME_VAL(QMI_LOC_SET_BLACKLIST_SV_RESP_V02),
    NAME_VAL(QMI_LOC_SET_BLACKLIST_SV_IND_V02),
    NAME_VAL(QMI_LOC_GET_BLACKLIST_SV_REQ_V02),
    NAME_VAL(QMI_LOC_GET_BLACKLIST_SV_RESP_V02),
    NAME_VAL(QMI_LOC_GET_BLACKLIST_SV_IND_V02),
    NAME_VAL(QMI_LOC_SET_CONSTELLATION_CONTROL_REQ_V02),
    NAME_VAL(QMI_LOC_SET_CONSTELLATION_CONTROL_RESP_V02),
    NAME_VAL(QMI_LOC_SET_CONSTELLATION_CONTROL_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_UNPROPAGATED_POSITION_REPORT_IND_V02),
    NAME_VAL(QMI_LOC_GET_BS_OBS_DATA_REQ_V02),
    NAME_VAL(QMI_LOC_GET_BS_OBS_DATA_RESP_V02),
    NAME_VAL(QMI_LOC_GET_BS_OBS_DATA_IND_V02),
    NAME_VAL(QMI_LOC_GET_CONSTELLATION_CONTROL_REQ_V02),
    NAME_VAL(QMI_LOC_GET_CONSTELLATION_CONTROL_RESP_V02),
    NAME_VAL(QMI_LOC_GET_CONSTELLATION_CONTROL_IND_V02),
    NAME_VAL(QMI_LOC_EVENT_BS_OBS_DATA_SERVICE_REQ_IND_V02),
    NAME_VAL(QMI_LOC_SET_CONSTRAINED_TUNC_MODE_REQ_V02),
    NAME_VAL(QMI_LOC_SET_CONSTRAINED_TUNC_MODE_RESP_V02),
    NAME_VAL(QMI_LOC_SET_CONSTRAINED_TUNC_MODE_IND_V02),
    NAME_VAL(QMI_LOC_ENABLE_POSITION_ASSISTED_CLOCK_EST_REQ_V02),
    NAME_VAL(QMI_LOC_ENABLE_POSITION_ASSISTED_CLOCK_EST_RESP_V02),
    NAME_VAL(QMI_LOC_ENABLE_POSITION_ASSISTED_CLOCK_EST_IND_V02),
    NAME_VAL(QMI_LOC_QUERY_GNSS_ENERGY_CONSUMED_REQ_V02),
    NAME_VAL(QMI_LOC_QUERY_GNSS_ENERGY_CONSUMED_RESP_V02),
    NAME_VAL(QMI_LOC_QUERY_GNSS_ENERGY_CONSUMED_IND_V02),
};
static const int loc_v02_event_num = sizeof(loc_v02_event_name) / sizeof(loc_name_val_s_type);

const char* loc_get_v02_event_name(uint32_t event)
{
    return loc_get_name_from_val(loc_v02_event_name, loc_v02_event_num, (long) event);
}

static const loc_name_val_s_type loc_v02_client_status_name[] =
{
    NAME_VAL(eLOC_CLIENT_SUCCESS),
    NAME_VAL(eLOC_CLIENT_FAILURE_GENERAL),
    NAME_VAL(eLOC_CLIENT_FAILURE_UNSUPPORTED),
    NAME_VAL(eLOC_CLIENT_FAILURE_INVALID_PARAMETER),
    NAME_VAL(eLOC_CLIENT_FAILURE_ENGINE_BUSY),
    NAME_VAL(eLOC_CLIENT_FAILURE_PHONE_OFFLINE),
    NAME_VAL(eLOC_CLIENT_FAILURE_TIMEOUT),
    NAME_VAL(eLOC_CLIENT_FAILURE_SERVICE_NOT_PRESENT),
    NAME_VAL(eLOC_CLIENT_FAILURE_SERVICE_VERSION_UNSUPPORTED),
    NAME_VAL(eLOC_CLIENT_FAILURE_CLIENT_VERSION_UNSUPPORTED),
    NAME_VAL(eLOC_CLIENT_FAILURE_INVALID_HANDLE),
    NAME_VAL(eLOC_CLIENT_FAILURE_INTERNAL),
    NAME_VAL(eLOC_CLIENT_FAILURE_NOT_INITIALIZED),
    NAME_VAL(eLOC_CLIENT_FAILURE_NOT_ENOUGH_MEMORY),
};
static const int loc_v02_client_status_num = sizeof(loc_v02_client_status_name) / sizeof(loc_name_val_s_type);

const char* loc_get_v02_client_status_name(locClientStatusEnumType status)
{
    return loc_get_name_from_val(loc_v02_client_status_name, loc_v02_client_status_num, (long) status);
}


static const loc_name_val_s_type loc_v02_qmi_status_name[] =
{
    NAME_VAL(eQMI_LOC_SUCCESS_V02),
    NAME_VAL(eQMI_LOC_GENERAL_FAILURE_V02),
    NAME_VAL(eQMI_LOC_UNSUPPORTED_V02),
    NAME_VAL(eQMI_LOC_INVALID_PARAMETER_V02),
    NAME_VAL(eQMI_LOC_ENGINE_BUSY_V02),
    NAME_VAL(eQMI_LOC_PHONE_OFFLINE_V02),
    NAME_VAL(eQMI_LOC_TIMEOUT_V02),
    NAME_VAL(eQMI_LOC_CONFIG_NOT_SUPPORTED_V02),
    NAME_VAL(eQMI_LOC_INSUFFICIENT_MEMORY_V02),
    NAME_VAL(eQMI_LOC_MAX_GEOFENCE_PROGRAMMED_V02),
    NAME_VAL(eQMI_LOC_XTRA_VERSION_CHECK_FAILURE_V02),
    NAME_VAL(eQMI_LOC_GNSS_DISABLED_V02),
};
static const int loc_v02_qmi_status_num = sizeof(loc_v02_qmi_status_name) / sizeof(loc_name_val_s_type);

const char* loc_get_v02_qmi_status_name(qmiLocStatusEnumT_v02 status)
{
    return loc_get_name_from_val(loc_v02_qmi_status_name, loc_v02_qmi_status_num, (long) status);
}


static const loc_name_val_s_type loc_v02_qmi_reg_mk_status_name[] =
{
    NAME_VAL(eQMI_LOC_REGISTER_MASTER_CLIENT_SUCCESS_V02),
    NAME_VAL(eQMI_LOC_REGISTER_MASTER_CLIENT_INVALID_KEY_V02),
    NAME_VAL(eQMI_LOC_REGISTER_MASTER_CLIENT_ALREADY_HAVE_MASTER_CLIENT_V02),
    NAME_VAL(eQMI_LOC_REGISTER_MASTER_CLIENT_INTERNAL_FAILURE_V02),
};
static const int loc_v02_qmi_reg_mk_status_num = sizeof(loc_v02_qmi_reg_mk_status_name) / sizeof(loc_name_val_s_type);

const char* loc_get_v02_qmi_reg_mk_status_name(qmiLocRegisterMasterClientStatusEnumT_v02 status)
{
    return loc_get_name_from_val(loc_v02_qmi_reg_mk_status_name, loc_v02_qmi_reg_mk_status_num, (long)status);
}
