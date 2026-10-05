// Copyright 2025 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GEN_COMPONENTS_AUTOFILL_CORE_BROWSER_DATA_MODEL_AUTOFILL_AI_ENTITY_TYPE_NAMES_H_
#define GEN_COMPONENTS_AUTOFILL_CORE_BROWSER_DATA_MODEL_AUTOFILL_AI_ENTITY_TYPE_NAMES_H_

namespace autofill {

// GENERATED_JAVA_ENUM_PACKAGE: org.chromium.components.autofill.autofill_ai
enum class EntityTypeName { kPassport, kDriversLicense, kVehicle, kNationalIdCard, kKnownTravelerNumber, kRedressNumber, kFlightReservation, kOrder, kShipment, kMaxValue = kShipment };

// GENERATED_JAVA_ENUM_PACKAGE: org.chromium.components.autofill.autofill_ai
enum class AttributeTypeName { kPassportName, kPassportCountry, kPassportNumber, kPassportIssueDate, kPassportExpirationDate, kDriversLicenseName, kDriversLicenseState, kDriversLicenseNumber, kDriversLicenseIssueDate, kDriversLicenseExpirationDate, kVehicleMake, kVehicleModel, kVehicleYear, kVehicleOwner, kVehiclePlateNumber, kVehiclePlateState, kVehicleVin, kNationalIdCardName, kNationalIdCardCountry, kNationalIdCardNumber, kNationalIdCardIssueDate, kNationalIdCardExpirationDate, kKnownTravelerNumberName, kKnownTravelerNumberNumber, kKnownTravelerNumberExpirationDate, kRedressNumberName, kRedressNumberNumber, kFlightReservationFlightNumber, kFlightReservationTicketNumber, kFlightReservationConfirmationCode, kFlightReservationPassengerName, kFlightReservationDepartureAirport, kFlightReservationArrivalAirport, kFlightReservationDepartureDate, kOrderId, kOrderAccount, kOrderDate, kOrderMerchantName, kOrderMerchantDomain, kOrderProductNames, kShipmentTrackingNumber, kShipmentDeliveryZipCode, kShipmentCarrierName, kShipmentCarrierDomain, kShipmentShippedDate, kShipmentMerchantName, kShipmentProductNames, kMaxValue = kShipmentProductNames };

}  // namespace autofill

#endif  // GEN_COMPONENTS_AUTOFILL_CORE_BROWSER_DATA_MODEL_AUTOFILL_AI_ENTITY_TYPE_NAMES_H_
