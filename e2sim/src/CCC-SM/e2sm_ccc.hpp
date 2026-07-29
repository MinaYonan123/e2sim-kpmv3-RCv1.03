//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     E2SmCcc data = nlohmann::json::parse(jsonString);

#pragma once

#include <boost/optional.hpp>
#include "nlohmann/json.hpp"

#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::make_shared<T>(); else return std::make_shared<T>(j.get<T>());
        }
    };
    template <typename T>
    struct adl_serializer<boost::optional<T>> {
        static void to_json(json & j, const boost::optional<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static boost::optional<T> from_json(const json & j) {
            if (j.is_null()) return boost::optional<T>(); else return boost::optional<T>(j.get<T>());
        }
    };
}
#endif

namespace quicktype {
    using nlohmann::json;

    #ifndef NLOHMANN_UNTYPED_quicktype_HELPER
    #define NLOHMANN_UNTYPED_quicktype_HELPER
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    #endif

    #ifndef NLOHMANN_OPTIONAL_quicktype_HELPER
    #define NLOHMANN_OPTIONAL_quicktype_HELPER
    template <typename T>
    inline std::shared_ptr<T> get_heap_optional(const json & j, const char * property) {
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_heap_optional(const json & j, std::string property) {
        return get_heap_optional<T>(j, property.data());
    }
    template <typename T>
    inline boost::optional<T> get_stack_optional(const json & j, const char * property) {
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
            return j.at(property).get<boost::optional<T>>();
        }
        return boost::optional<T>();
    }

    template <typename T>
    inline boost::optional<T> get_stack_optional(const json & j, std::string property) {
        return get_stack_optional<T>(j, property.data());
    }
    #endif

    class ItemsElement {
        public:
        ItemsElement() = default;
        virtual ~ItemsElement() = default;

        private:
        std::string ref;

        public:
        const std::string & get_ref() const { return ref; }
        std::string & get_mutable_ref() { return ref; }
        void set_ref(const std::string & value) { this->ref = value; }
    };

    class ActionDefinitionFormat {
        public:
        ActionDefinitionFormat() = default;
        virtual ~ActionDefinitionFormat() = default;

        private:
        std::vector<ItemsElement> one_of;

        public:
        const std::vector<ItemsElement> & get_one_of() const { return one_of; }
        std::vector<ItemsElement> & get_mutable_one_of() { return one_of; }
        void set_one_of(const std::vector<ItemsElement> & value) { this->one_of = value; }
    };

    enum class EutraCellIdentityType : int { BOOLEAN, INTEGER, NUMBER, OBJECT, STRING };

    class AdministrativeState {
        public:
        AdministrativeState() = default;
        virtual ~AdministrativeState() = default;

        private:
        EutraCellIdentityType type;
        std::vector<std::string> administrative_state_enum;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const std::vector<std::string> & get_administrative_state_enum() const { return administrative_state_enum; }
        std::vector<std::string> & get_mutable_administrative_state_enum() { return administrative_state_enum; }
        void set_administrative_state_enum(const std::vector<std::string> & value) { this->administrative_state_enum = value; }
    };

    class EutraCellIdentity {
        public:
        EutraCellIdentity() = default;
        virtual ~EutraCellIdentity() = default;

        private:
        EutraCellIdentityType type;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }
    };

    class AsmCapabilityInfoProperties {
        public:
        AsmCapabilityInfoProperties() = default;
        virtual ~AsmCapabilityInfoProperties() = default;

        private:
        ItemsElement sleep_modes;
        EutraCellIdentity defined_duration_sleep_supported;
        EutraCellIdentity undefined_duration_sleep_supported;
        boost::optional<ItemsElement> supported_trx_control_masks;

        public:
        const ItemsElement & get_sleep_modes() const { return sleep_modes; }
        ItemsElement & get_mutable_sleep_modes() { return sleep_modes; }
        void set_sleep_modes(const ItemsElement & value) { this->sleep_modes = value; }

        const EutraCellIdentity & get_defined_duration_sleep_supported() const { return defined_duration_sleep_supported; }
        EutraCellIdentity & get_mutable_defined_duration_sleep_supported() { return defined_duration_sleep_supported; }
        void set_defined_duration_sleep_supported(const EutraCellIdentity & value) { this->defined_duration_sleep_supported = value; }

        const EutraCellIdentity & get_undefined_duration_sleep_supported() const { return undefined_duration_sleep_supported; }
        EutraCellIdentity & get_mutable_undefined_duration_sleep_supported() { return undefined_duration_sleep_supported; }
        void set_undefined_duration_sleep_supported(const EutraCellIdentity & value) { this->undefined_duration_sleep_supported = value; }

        boost::optional<ItemsElement> get_supported_trx_control_masks() const { return supported_trx_control_masks; }
        void set_supported_trx_control_masks(boost::optional<ItemsElement> value) { this->supported_trx_control_masks = value; }
    };

    class CapabilityInfo {
        public:
        CapabilityInfo() = default;
        virtual ~CapabilityInfo() = default;

        private:
        EutraCellIdentityType type;
        AsmCapabilityInfoProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const AsmCapabilityInfoProperties & get_properties() const { return properties; }
        AsmCapabilityInfoProperties & get_mutable_properties() { return properties; }
        void set_properties(const AsmCapabilityInfoProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class AttributeProperties {
        public:
        AttributeProperties() = default;
        virtual ~AttributeProperties() = default;

        private:
        EutraCellIdentity attribute_name;
        ItemsElement supported_services;

        public:
        const EutraCellIdentity & get_attribute_name() const { return attribute_name; }
        EutraCellIdentity & get_mutable_attribute_name() { return attribute_name; }
        void set_attribute_name(const EutraCellIdentity & value) { this->attribute_name = value; }

        const ItemsElement & get_supported_services() const { return supported_services; }
        ItemsElement & get_mutable_supported_services() { return supported_services; }
        void set_supported_services(const ItemsElement & value) { this->supported_services = value; }
    };

    class Attribute {
        public:
        Attribute() = default;
        virtual ~Attribute() = default;

        private:
        EutraCellIdentityType type;
        AttributeProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const AttributeProperties & get_properties() const { return properties; }
        AttributeProperties & get_mutable_properties() { return properties; }
        void set_properties(const AttributeProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class AttributeNameProperties {
        public:
        AttributeNameProperties() = default;
        virtual ~AttributeNameProperties() = default;

        private:
        EutraCellIdentity attribute_name;

        public:
        const EutraCellIdentity & get_attribute_name() const { return attribute_name; }
        EutraCellIdentity & get_mutable_attribute_name() { return attribute_name; }
        void set_attribute_name(const EutraCellIdentity & value) { this->attribute_name = value; }
    };

    class AttributeName {
        public:
        AttributeName() = default;
        virtual ~AttributeName() = default;

        private:
        EutraCellIdentityType type;
        AttributeNameProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const AttributeNameProperties & get_properties() const { return properties; }
        AttributeNameProperties & get_mutable_properties() { return properties; }
        void set_properties(const AttributeNameProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class CellConfigurationToBeReportedForAdfProperties {
        public:
        CellConfigurationToBeReportedForAdfProperties() = default;
        virtual ~CellConfigurationToBeReportedForAdfProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement list_of_cell_level_ran_configuration_structures_for_adf;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_list_of_cell_level_ran_configuration_structures_for_adf() const { return list_of_cell_level_ran_configuration_structures_for_adf; }
        ItemsElement & get_mutable_list_of_cell_level_ran_configuration_structures_for_adf() { return list_of_cell_level_ran_configuration_structures_for_adf; }
        void set_list_of_cell_level_ran_configuration_structures_for_adf(const ItemsElement & value) { this->list_of_cell_level_ran_configuration_structures_for_adf = value; }
    };

    class CellConfigurationToBeReportedForAdf {
        public:
        CellConfigurationToBeReportedForAdf() = default;
        virtual ~CellConfigurationToBeReportedForAdf() = default;

        private:
        EutraCellIdentityType type;
        CellConfigurationToBeReportedForAdfProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellConfigurationToBeReportedForAdfProperties & get_properties() const { return properties; }
        CellConfigurationToBeReportedForAdfProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellConfigurationToBeReportedForAdfProperties & value) { this->properties = value; }
    };

    class CellControlOutcomeProperties {
        public:
        CellControlOutcomeProperties() = default;
        virtual ~CellControlOutcomeProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement ran_configuration_structures_accepted_list;
        ItemsElement ran_configuration_structures_failed_list;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_ran_configuration_structures_accepted_list() const { return ran_configuration_structures_accepted_list; }
        ItemsElement & get_mutable_ran_configuration_structures_accepted_list() { return ran_configuration_structures_accepted_list; }
        void set_ran_configuration_structures_accepted_list(const ItemsElement & value) { this->ran_configuration_structures_accepted_list = value; }

        const ItemsElement & get_ran_configuration_structures_failed_list() const { return ran_configuration_structures_failed_list; }
        ItemsElement & get_mutable_ran_configuration_structures_failed_list() { return ran_configuration_structures_failed_list; }
        void set_ran_configuration_structures_failed_list(const ItemsElement & value) { this->ran_configuration_structures_failed_list = value; }
    };

    class CellControlOutcome {
        public:
        CellControlOutcome() = default;
        virtual ~CellControlOutcome() = default;

        private:
        EutraCellIdentityType type;
        CellControlOutcomeProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellControlOutcomeProperties & get_properties() const { return properties; }
        CellControlOutcomeProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellControlOutcomeProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class CellControlledProperties {
        public:
        CellControlledProperties() = default;
        virtual ~CellControlledProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement list_of_configuration_structures;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_list_of_configuration_structures() const { return list_of_configuration_structures; }
        ItemsElement & get_mutable_list_of_configuration_structures() { return list_of_configuration_structures; }
        void set_list_of_configuration_structures(const ItemsElement & value) { this->list_of_configuration_structures = value; }
    };

    class CellControlled {
        public:
        CellControlled() = default;
        virtual ~CellControlled() = default;

        private:
        EutraCellIdentityType type;
        CellControlledProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellControlledProperties & get_properties() const { return properties; }
        CellControlledProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellControlledProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class CellForRanFunctionDefinitionProperties {
        public:
        CellForRanFunctionDefinitionProperties() = default;
        virtual ~CellForRanFunctionDefinitionProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement list_of_supported_cell_level_ran_configuration_structures;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_list_of_supported_cell_level_ran_configuration_structures() const { return list_of_supported_cell_level_ran_configuration_structures; }
        ItemsElement & get_mutable_list_of_supported_cell_level_ran_configuration_structures() { return list_of_supported_cell_level_ran_configuration_structures; }
        void set_list_of_supported_cell_level_ran_configuration_structures(const ItemsElement & value) { this->list_of_supported_cell_level_ran_configuration_structures = value; }
    };

    class CellForRanFunctionDefinition {
        public:
        CellForRanFunctionDefinition() = default;
        virtual ~CellForRanFunctionDefinition() = default;

        private:
        EutraCellIdentityType type;
        CellForRanFunctionDefinitionProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellForRanFunctionDefinitionProperties & get_properties() const { return properties; }
        CellForRanFunctionDefinitionProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellForRanFunctionDefinitionProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class CellGlobalId {
        public:
        CellGlobalId() = default;
        virtual ~CellGlobalId() = default;

        private:
        EutraCellIdentityType type;
        std::vector<ItemsElement> one_of;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const std::vector<ItemsElement> & get_one_of() const { return one_of; }
        std::vector<ItemsElement> & get_mutable_one_of() { return one_of; }
        void set_one_of(const std::vector<ItemsElement> & value) { this->one_of = value; }
    };

    class CellLevelConfigurationStructureForEventTriggerProperties {
        public:
        CellLevelConfigurationStructureForEventTriggerProperties() = default;
        virtual ~CellLevelConfigurationStructureForEventTriggerProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement list_of_ran_configuration_structures_for_event_trigger;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_list_of_ran_configuration_structures_for_event_trigger() const { return list_of_ran_configuration_structures_for_event_trigger; }
        ItemsElement & get_mutable_list_of_ran_configuration_structures_for_event_trigger() { return list_of_ran_configuration_structures_for_event_trigger; }
        void set_list_of_ran_configuration_structures_for_event_trigger(const ItemsElement & value) { this->list_of_ran_configuration_structures_for_event_trigger = value; }
    };

    class CellLevelConfigurationStructureForEventTrigger {
        public:
        CellLevelConfigurationStructureForEventTrigger() = default;
        virtual ~CellLevelConfigurationStructureForEventTrigger() = default;

        private:
        EutraCellIdentityType type;
        CellLevelConfigurationStructureForEventTriggerProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellLevelConfigurationStructureForEventTriggerProperties & get_properties() const { return properties; }
        CellLevelConfigurationStructureForEventTriggerProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellLevelConfigurationStructureForEventTriggerProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class CellReportedProperties {
        public:
        CellReportedProperties() = default;
        virtual ~CellReportedProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement list_of_configuration_structures_reported;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_list_of_configuration_structures_reported() const { return list_of_configuration_structures_reported; }
        ItemsElement & get_mutable_list_of_configuration_structures_reported() { return list_of_configuration_structures_reported; }
        void set_list_of_configuration_structures_reported(const ItemsElement & value) { this->list_of_configuration_structures_reported = value; }
    };

    class CellReported {
        public:
        CellReported() = default;
        virtual ~CellReported() = default;

        private:
        EutraCellIdentityType type;
        CellReportedProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellReportedProperties & get_properties() const { return properties; }
        CellReportedProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellReportedProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    enum class The5QiListType : int { ARRAY };

    class GEnbIdList {
        public:
        GEnbIdList() = default;
        virtual ~GEnbIdList() = default;

        private:
        The5QiListType type;
        ItemsElement items;

        public:
        const The5QiListType & get_type() const { return type; }
        The5QiListType & get_mutable_type() { return type; }
        void set_type(const The5QiListType & value) { this->type = value; }

        const ItemsElement & get_items() const { return items; }
        ItemsElement & get_mutable_items() { return items; }
        void set_items(const ItemsElement & value) { this->items = value; }
    };

    class CelllevelConfigurationStructuresForQueryProperties {
        public:
        CelllevelConfigurationStructuresForQueryProperties() = default;
        virtual ~CelllevelConfigurationStructuresForQueryProperties() = default;

        private:
        EutraCellIdentity ran_configuration_structure_name;
        GEnbIdList list_of_attributes;

        public:
        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const GEnbIdList & get_list_of_attributes() const { return list_of_attributes; }
        GEnbIdList & get_mutable_list_of_attributes() { return list_of_attributes; }
        void set_list_of_attributes(const GEnbIdList & value) { this->list_of_attributes = value; }
    };

    class ConfigurationStructuresForQuery {
        public:
        ConfigurationStructuresForQuery() = default;
        virtual ~ConfigurationStructuresForQuery() = default;

        private:
        EutraCellIdentityType type;
        CelllevelConfigurationStructuresForQueryProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CelllevelConfigurationStructuresForQueryProperties & get_properties() const { return properties; }
        CelllevelConfigurationStructuresForQueryProperties & get_mutable_properties() { return properties; }
        void set_properties(const CelllevelConfigurationStructuresForQueryProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class CellsToBeQueriedProperties {
        public:
        CellsToBeQueriedProperties() = default;
        virtual ~CellsToBeQueriedProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement list_of_celllevel_configuration_structures_for_query;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_list_of_celllevel_configuration_structures_for_query() const { return list_of_celllevel_configuration_structures_for_query; }
        ItemsElement & get_mutable_list_of_celllevel_configuration_structures_for_query() { return list_of_celllevel_configuration_structures_for_query; }
        void set_list_of_celllevel_configuration_structures_for_query(const ItemsElement & value) { this->list_of_celllevel_configuration_structures_for_query = value; }
    };

    class CellsToBeQueried {
        public:
        CellsToBeQueried() = default;
        virtual ~CellsToBeQueried() = default;

        private:
        EutraCellIdentityType type;
        CellsToBeQueriedProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellsToBeQueriedProperties & get_properties() const { return properties; }
        CellsToBeQueriedProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellsToBeQueriedProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class CellsToBeReportedForQueryProperties {
        public:
        CellsToBeReportedForQueryProperties() = default;
        virtual ~CellsToBeReportedForQueryProperties() = default;

        private:
        ItemsElement cell_global_id;
        ItemsElement list_of_configuration_structures_to_be_reported_for_query;

        public:
        const ItemsElement & get_cell_global_id() const { return cell_global_id; }
        ItemsElement & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const ItemsElement & value) { this->cell_global_id = value; }

        const ItemsElement & get_list_of_configuration_structures_to_be_reported_for_query() const { return list_of_configuration_structures_to_be_reported_for_query; }
        ItemsElement & get_mutable_list_of_configuration_structures_to_be_reported_for_query() { return list_of_configuration_structures_to_be_reported_for_query; }
        void set_list_of_configuration_structures_to_be_reported_for_query(const ItemsElement & value) { this->list_of_configuration_structures_to_be_reported_for_query = value; }
    };

    class CellsToBeReportedForQuery {
        public:
        CellsToBeReportedForQuery() = default;
        virtual ~CellsToBeReportedForQuery() = default;

        private:
        EutraCellIdentityType type;
        CellsToBeReportedForQueryProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CellsToBeReportedForQueryProperties & get_properties() const { return properties; }
        CellsToBeReportedForQueryProperties & get_mutable_properties() { return properties; }
        void set_properties(const CellsToBeReportedForQueryProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ChangeType {
        public:
        ChangeType() = default;
        virtual ~ChangeType() = default;

        private:
        std::vector<std::string> change_type_enum;

        public:
        const std::vector<std::string> & get_change_type_enum() const { return change_type_enum; }
        std::vector<std::string> & get_mutable_change_type_enum() { return change_type_enum; }
        void set_change_type_enum(const std::vector<std::string> & value) { this->change_type_enum = value; }
    };

    class ConfigurationStructureProperties {
        public:
        ConfigurationStructureProperties() = default;
        virtual ~ConfigurationStructureProperties() = default;

        private:
        ChangeType change_type;
        EutraCellIdentity ran_configuration_structure_name;
        ItemsElement values_of_attributes;
        ItemsElement old_values_of_attributes;

        public:
        const ChangeType & get_change_type() const { return change_type; }
        ChangeType & get_mutable_change_type() { return change_type; }
        void set_change_type(const ChangeType & value) { this->change_type = value; }

        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const ItemsElement & get_values_of_attributes() const { return values_of_attributes; }
        ItemsElement & get_mutable_values_of_attributes() { return values_of_attributes; }
        void set_values_of_attributes(const ItemsElement & value) { this->values_of_attributes = value; }

        const ItemsElement & get_old_values_of_attributes() const { return old_values_of_attributes; }
        ItemsElement & get_mutable_old_values_of_attributes() { return old_values_of_attributes; }
        void set_old_values_of_attributes(const ItemsElement & value) { this->old_values_of_attributes = value; }
    };

    class ConfigurationStructure {
        public:
        ConfigurationStructure() = default;
        virtual ~ConfigurationStructure() = default;

        private:
        EutraCellIdentityType type;
        ConfigurationStructureProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ConfigurationStructureProperties & get_properties() const { return properties; }
        ConfigurationStructureProperties & get_mutable_properties() { return properties; }
        void set_properties(const ConfigurationStructureProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ConfigurationStructureAcceptedProperties {
        public:
        ConfigurationStructureAcceptedProperties() = default;
        virtual ~ConfigurationStructureAcceptedProperties() = default;

        private:
        EutraCellIdentity ran_configuration_structure_name;
        ItemsElement old_values_of_attributes;
        ItemsElement current_values_of_attributes;
        EutraCellIdentity applied_timestamp;

        public:
        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const ItemsElement & get_old_values_of_attributes() const { return old_values_of_attributes; }
        ItemsElement & get_mutable_old_values_of_attributes() { return old_values_of_attributes; }
        void set_old_values_of_attributes(const ItemsElement & value) { this->old_values_of_attributes = value; }

        const ItemsElement & get_current_values_of_attributes() const { return current_values_of_attributes; }
        ItemsElement & get_mutable_current_values_of_attributes() { return current_values_of_attributes; }
        void set_current_values_of_attributes(const ItemsElement & value) { this->current_values_of_attributes = value; }

        const EutraCellIdentity & get_applied_timestamp() const { return applied_timestamp; }
        EutraCellIdentity & get_mutable_applied_timestamp() { return applied_timestamp; }
        void set_applied_timestamp(const EutraCellIdentity & value) { this->applied_timestamp = value; }
    };

    class ConfigurationStructureAccepted {
        public:
        ConfigurationStructureAccepted() = default;
        virtual ~ConfigurationStructureAccepted() = default;

        private:
        EutraCellIdentityType type;
        ConfigurationStructureAcceptedProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ConfigurationStructureAcceptedProperties & get_properties() const { return properties; }
        ConfigurationStructureAcceptedProperties & get_mutable_properties() { return properties; }
        void set_properties(const ConfigurationStructureAcceptedProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ConfigurationStructureFailedProperties {
        public:
        ConfigurationStructureFailedProperties() = default;
        virtual ~ConfigurationStructureFailedProperties() = default;

        private:
        EutraCellIdentity ran_configuration_structure_name;
        ItemsElement old_values_of_attributes;
        ItemsElement requested_values_of_attributes;
        ItemsElement cause;

        public:
        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const ItemsElement & get_old_values_of_attributes() const { return old_values_of_attributes; }
        ItemsElement & get_mutable_old_values_of_attributes() { return old_values_of_attributes; }
        void set_old_values_of_attributes(const ItemsElement & value) { this->old_values_of_attributes = value; }

        const ItemsElement & get_requested_values_of_attributes() const { return requested_values_of_attributes; }
        ItemsElement & get_mutable_requested_values_of_attributes() { return requested_values_of_attributes; }
        void set_requested_values_of_attributes(const ItemsElement & value) { this->requested_values_of_attributes = value; }

        const ItemsElement & get_cause() const { return cause; }
        ItemsElement & get_mutable_cause() { return cause; }
        void set_cause(const ItemsElement & value) { this->cause = value; }
    };

    class ConfigurationStructureFailed {
        public:
        ConfigurationStructureFailed() = default;
        virtual ~ConfigurationStructureFailed() = default;

        private:
        EutraCellIdentityType type;
        ConfigurationStructureFailedProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ConfigurationStructureFailedProperties & get_properties() const { return properties; }
        ConfigurationStructureFailedProperties & get_mutable_properties() { return properties; }
        void set_properties(const ConfigurationStructureFailedProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ConfigurationStructureWriteProperties {
        public:
        ConfigurationStructureWriteProperties() = default;
        virtual ~ConfigurationStructureWriteProperties() = default;

        private:
        EutraCellIdentity ran_configuration_structure_name;
        ItemsElement old_values_of_attributes;
        ItemsElement new_values_of_attributes;

        public:
        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const ItemsElement & get_old_values_of_attributes() const { return old_values_of_attributes; }
        ItemsElement & get_mutable_old_values_of_attributes() { return old_values_of_attributes; }
        void set_old_values_of_attributes(const ItemsElement & value) { this->old_values_of_attributes = value; }

        const ItemsElement & get_new_values_of_attributes() const { return new_values_of_attributes; }
        ItemsElement & get_mutable_new_values_of_attributes() { return new_values_of_attributes; }
        void set_new_values_of_attributes(const ItemsElement & value) { this->new_values_of_attributes = value; }
    };

    class ConfigurationStructureWrite {
        public:
        ConfigurationStructureWrite() = default;
        virtual ~ConfigurationStructureWrite() = default;

        private:
        EutraCellIdentityType type;
        ConfigurationStructureWriteProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ConfigurationStructureWriteProperties & get_properties() const { return properties; }
        ConfigurationStructureWriteProperties & get_mutable_properties() { return properties; }
        void set_properties(const ConfigurationStructureWriteProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ConfigurationStructuresToBeReportedForQueryProperties {
        public:
        ConfigurationStructuresToBeReportedForQueryProperties() = default;
        virtual ~ConfigurationStructuresToBeReportedForQueryProperties() = default;

        private:
        EutraCellIdentity ran_configuration_structure_name;
        ItemsElement values_of_attributes;

        public:
        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const ItemsElement & get_values_of_attributes() const { return values_of_attributes; }
        ItemsElement & get_mutable_values_of_attributes() { return values_of_attributes; }
        void set_values_of_attributes(const ItemsElement & value) { this->values_of_attributes = value; }
    };

    class ConfigurationStructuresToBeReportedForQuery {
        public:
        ConfigurationStructuresToBeReportedForQuery() = default;
        virtual ~ConfigurationStructuresToBeReportedForQuery() = default;

        private:
        EutraCellIdentityType type;
        ConfigurationStructuresToBeReportedForQueryProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ConfigurationStructuresToBeReportedForQueryProperties & get_properties() const { return properties; }
        ConfigurationStructuresToBeReportedForQueryProperties & get_mutable_properties() { return properties; }
        void set_properties(const ConfigurationStructuresToBeReportedForQueryProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ControlServiceProperties {
        public:
        ControlServiceProperties() = default;
        virtual ~ControlServiceProperties() = default;

        private:
        ItemsElement list_of_supported_control_styles;

        public:
        const ItemsElement & get_list_of_supported_control_styles() const { return list_of_supported_control_styles; }
        ItemsElement & get_mutable_list_of_supported_control_styles() { return list_of_supported_control_styles; }
        void set_list_of_supported_control_styles(const ItemsElement & value) { this->list_of_supported_control_styles = value; }
    };

    class ControlService {
        public:
        ControlService() = default;
        virtual ~ControlService() = default;

        private:
        EutraCellIdentityType type;
        ControlServiceProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ControlServiceProperties & get_properties() const { return properties; }
        ControlServiceProperties & get_mutable_properties() { return properties; }
        void set_properties(const ControlServiceProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ControlStyleProperties {
        public:
        ControlStyleProperties() = default;
        virtual ~ControlStyleProperties() = default;

        private:
        EutraCellIdentity control_service_style_type;
        EutraCellIdentity control_service_style_name;
        EutraCellIdentity control_service_header_format_type;
        EutraCellIdentity control_service_message_format_type;
        EutraCellIdentity ric_call_process_id_format_type;
        EutraCellIdentity control_service_control_outcome_format_type;

        public:
        const EutraCellIdentity & get_control_service_style_type() const { return control_service_style_type; }
        EutraCellIdentity & get_mutable_control_service_style_type() { return control_service_style_type; }
        void set_control_service_style_type(const EutraCellIdentity & value) { this->control_service_style_type = value; }

        const EutraCellIdentity & get_control_service_style_name() const { return control_service_style_name; }
        EutraCellIdentity & get_mutable_control_service_style_name() { return control_service_style_name; }
        void set_control_service_style_name(const EutraCellIdentity & value) { this->control_service_style_name = value; }

        const EutraCellIdentity & get_control_service_header_format_type() const { return control_service_header_format_type; }
        EutraCellIdentity & get_mutable_control_service_header_format_type() { return control_service_header_format_type; }
        void set_control_service_header_format_type(const EutraCellIdentity & value) { this->control_service_header_format_type = value; }

        const EutraCellIdentity & get_control_service_message_format_type() const { return control_service_message_format_type; }
        EutraCellIdentity & get_mutable_control_service_message_format_type() { return control_service_message_format_type; }
        void set_control_service_message_format_type(const EutraCellIdentity & value) { this->control_service_message_format_type = value; }

        const EutraCellIdentity & get_ric_call_process_id_format_type() const { return ric_call_process_id_format_type; }
        EutraCellIdentity & get_mutable_ric_call_process_id_format_type() { return ric_call_process_id_format_type; }
        void set_ric_call_process_id_format_type(const EutraCellIdentity & value) { this->ric_call_process_id_format_type = value; }

        const EutraCellIdentity & get_control_service_control_outcome_format_type() const { return control_service_control_outcome_format_type; }
        EutraCellIdentity & get_mutable_control_service_control_outcome_format_type() { return control_service_control_outcome_format_type; }
        void set_control_service_control_outcome_format_type(const EutraCellIdentity & value) { this->control_service_control_outcome_format_type = value; }
    };

    class ControlStyle {
        public:
        ControlStyle() = default;
        virtual ~ControlStyle() = default;

        private:
        EutraCellIdentityType type;
        ControlStyleProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ControlStyleProperties & get_properties() const { return properties; }
        ControlStyleProperties & get_mutable_properties() { return properties; }
        void set_properties(const ControlStyleProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class GnbCuUpId {
        public:
        GnbCuUpId() = default;
        virtual ~GnbCuUpId() = default;

        private:
        EutraCellIdentityType type;
        boost::optional<int64_t> minimum;
        boost::optional<int64_t> maximum;
        boost::optional<std::vector<std::string>> gnb_cu_up_id_enum;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        boost::optional<int64_t> get_minimum() const { return minimum; }
        void set_minimum(boost::optional<int64_t> value) { this->minimum = value; }

        boost::optional<int64_t> get_maximum() const { return maximum; }
        void set_maximum(boost::optional<int64_t> value) { this->maximum = value; }

        boost::optional<std::vector<std::string>> get_gnb_cu_up_id_enum() const { return gnb_cu_up_id_enum; }
        void set_gnb_cu_up_id_enum(boost::optional<std::vector<std::string>> value) { this->gnb_cu_up_id_enum = value; }
    };

    class CycleStartOffsetProperties {
        public:
        CycleStartOffsetProperties() = default;
        virtual ~CycleStartOffsetProperties() = default;

        private:
        AdministrativeState periodicity;
        GnbCuUpId offset;

        public:
        const AdministrativeState & get_periodicity() const { return periodicity; }
        AdministrativeState & get_mutable_periodicity() { return periodicity; }
        void set_periodicity(const AdministrativeState & value) { this->periodicity = value; }

        const GnbCuUpId & get_offset() const { return offset; }
        GnbCuUpId & get_mutable_offset() { return offset; }
        void set_offset(const GnbCuUpId & value) { this->offset = value; }
    };

    class CycleStartOffset {
        public:
        CycleStartOffset() = default;
        virtual ~CycleStartOffset() = default;

        private:
        EutraCellIdentityType type;
        CycleStartOffsetProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const CycleStartOffsetProperties & get_properties() const { return properties; }
        CycleStartOffsetProperties & get_mutable_properties() { return properties; }
        void set_properties(const CycleStartOffsetProperties & value) { this->properties = value; }
    };

    class E2SmCccActionDefinitionFormat1Properties {
        public:
        E2SmCccActionDefinitionFormat1Properties() = default;
        virtual ~E2SmCccActionDefinitionFormat1Properties() = default;

        private:
        ItemsElement list_of_node_level_ran_configuration_structures_for_adf;

        public:
        const ItemsElement & get_list_of_node_level_ran_configuration_structures_for_adf() const { return list_of_node_level_ran_configuration_structures_for_adf; }
        ItemsElement & get_mutable_list_of_node_level_ran_configuration_structures_for_adf() { return list_of_node_level_ran_configuration_structures_for_adf; }
        void set_list_of_node_level_ran_configuration_structures_for_adf(const ItemsElement & value) { this->list_of_node_level_ran_configuration_structures_for_adf = value; }
    };

    class E2SmCccActionDefinitionFormat1 {
        public:
        E2SmCccActionDefinitionFormat1() = default;
        virtual ~E2SmCccActionDefinitionFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccActionDefinitionFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccActionDefinitionFormat1Properties & get_properties() const { return properties; }
        E2SmCccActionDefinitionFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccActionDefinitionFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccActionDefinitionFormat2Properties {
        public:
        E2SmCccActionDefinitionFormat2Properties() = default;
        virtual ~E2SmCccActionDefinitionFormat2Properties() = default;

        private:
        ItemsElement list_of_cell_configurations_to_be_reported_for_adf;

        public:
        const ItemsElement & get_list_of_cell_configurations_to_be_reported_for_adf() const { return list_of_cell_configurations_to_be_reported_for_adf; }
        ItemsElement & get_mutable_list_of_cell_configurations_to_be_reported_for_adf() { return list_of_cell_configurations_to_be_reported_for_adf; }
        void set_list_of_cell_configurations_to_be_reported_for_adf(const ItemsElement & value) { this->list_of_cell_configurations_to_be_reported_for_adf = value; }
    };

    class E2SmCccActionDefinitionFormat2 {
        public:
        E2SmCccActionDefinitionFormat2() = default;
        virtual ~E2SmCccActionDefinitionFormat2() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccActionDefinitionFormat2Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccActionDefinitionFormat2Properties & get_properties() const { return properties; }
        E2SmCccActionDefinitionFormat2Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccActionDefinitionFormat2Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccControlHeaderFormat1Properties {
        public:
        E2SmCccControlHeaderFormat1Properties() = default;
        virtual ~E2SmCccControlHeaderFormat1Properties() = default;

        private:
        EutraCellIdentity ric_style_type;

        public:
        const EutraCellIdentity & get_ric_style_type() const { return ric_style_type; }
        EutraCellIdentity & get_mutable_ric_style_type() { return ric_style_type; }
        void set_ric_style_type(const EutraCellIdentity & value) { this->ric_style_type = value; }
    };

    class E2SmCccHeaderFormat1 {
        public:
        E2SmCccHeaderFormat1() = default;
        virtual ~E2SmCccHeaderFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccControlHeaderFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccControlHeaderFormat1Properties & get_properties() const { return properties; }
        E2SmCccControlHeaderFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccControlHeaderFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccControlMessageFormat1Properties {
        public:
        E2SmCccControlMessageFormat1Properties() = default;
        virtual ~E2SmCccControlMessageFormat1Properties() = default;

        private:
        ItemsElement list_of_configuration_structures;

        public:
        const ItemsElement & get_list_of_configuration_structures() const { return list_of_configuration_structures; }
        ItemsElement & get_mutable_list_of_configuration_structures() { return list_of_configuration_structures; }
        void set_list_of_configuration_structures(const ItemsElement & value) { this->list_of_configuration_structures = value; }
    };

    class E2SmCccControlMessageFormat1 {
        public:
        E2SmCccControlMessageFormat1() = default;
        virtual ~E2SmCccControlMessageFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccControlMessageFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccControlMessageFormat1Properties & get_properties() const { return properties; }
        E2SmCccControlMessageFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccControlMessageFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccControlMessageFormat2Properties {
        public:
        E2SmCccControlMessageFormat2Properties() = default;
        virtual ~E2SmCccControlMessageFormat2Properties() = default;

        private:
        ItemsElement list_of_cells_controlled;

        public:
        const ItemsElement & get_list_of_cells_controlled() const { return list_of_cells_controlled; }
        ItemsElement & get_mutable_list_of_cells_controlled() { return list_of_cells_controlled; }
        void set_list_of_cells_controlled(const ItemsElement & value) { this->list_of_cells_controlled = value; }
    };

    class E2SmCccControlMessageFormat2 {
        public:
        E2SmCccControlMessageFormat2() = default;
        virtual ~E2SmCccControlMessageFormat2() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccControlMessageFormat2Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccControlMessageFormat2Properties & get_properties() const { return properties; }
        E2SmCccControlMessageFormat2Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccControlMessageFormat2Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccControlOutcomeFormat1Properties {
        public:
        E2SmCccControlOutcomeFormat1Properties() = default;
        virtual ~E2SmCccControlOutcomeFormat1Properties() = default;

        private:
        EutraCellIdentity received_timestamp;
        ItemsElement ran_configuration_structures_accepted_list;
        ItemsElement ran_configuration_structures_failed_list;

        public:
        const EutraCellIdentity & get_received_timestamp() const { return received_timestamp; }
        EutraCellIdentity & get_mutable_received_timestamp() { return received_timestamp; }
        void set_received_timestamp(const EutraCellIdentity & value) { this->received_timestamp = value; }

        const ItemsElement & get_ran_configuration_structures_accepted_list() const { return ran_configuration_structures_accepted_list; }
        ItemsElement & get_mutable_ran_configuration_structures_accepted_list() { return ran_configuration_structures_accepted_list; }
        void set_ran_configuration_structures_accepted_list(const ItemsElement & value) { this->ran_configuration_structures_accepted_list = value; }

        const ItemsElement & get_ran_configuration_structures_failed_list() const { return ran_configuration_structures_failed_list; }
        ItemsElement & get_mutable_ran_configuration_structures_failed_list() { return ran_configuration_structures_failed_list; }
        void set_ran_configuration_structures_failed_list(const ItemsElement & value) { this->ran_configuration_structures_failed_list = value; }
    };

    class E2SmCccControlOutcomeFormat1 {
        public:
        E2SmCccControlOutcomeFormat1() = default;
        virtual ~E2SmCccControlOutcomeFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccControlOutcomeFormat1Properties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccControlOutcomeFormat1Properties & get_properties() const { return properties; }
        E2SmCccControlOutcomeFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccControlOutcomeFormat1Properties & value) { this->properties = value; }
    };

    class E2SmCccControlOutcomeFormat2Properties {
        public:
        E2SmCccControlOutcomeFormat2Properties() = default;
        virtual ~E2SmCccControlOutcomeFormat2Properties() = default;

        private:
        EutraCellIdentity received_timestamp;
        ItemsElement list_of_cells_for_control_outcome;

        public:
        const EutraCellIdentity & get_received_timestamp() const { return received_timestamp; }
        EutraCellIdentity & get_mutable_received_timestamp() { return received_timestamp; }
        void set_received_timestamp(const EutraCellIdentity & value) { this->received_timestamp = value; }

        const ItemsElement & get_list_of_cells_for_control_outcome() const { return list_of_cells_for_control_outcome; }
        ItemsElement & get_mutable_list_of_cells_for_control_outcome() { return list_of_cells_for_control_outcome; }
        void set_list_of_cells_for_control_outcome(const ItemsElement & value) { this->list_of_cells_for_control_outcome = value; }
    };

    class E2SmCccControlOutcomeFormat2 {
        public:
        E2SmCccControlOutcomeFormat2() = default;
        virtual ~E2SmCccControlOutcomeFormat2() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccControlOutcomeFormat2Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccControlOutcomeFormat2Properties & get_properties() const { return properties; }
        E2SmCccControlOutcomeFormat2Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccControlOutcomeFormat2Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccEventTriggerDefinitionFormat1Properties {
        public:
        E2SmCccEventTriggerDefinitionFormat1Properties() = default;
        virtual ~E2SmCccEventTriggerDefinitionFormat1Properties() = default;

        private:
        ItemsElement list_of_node_level_configuration_structures_for_event_trigger;

        public:
        const ItemsElement & get_list_of_node_level_configuration_structures_for_event_trigger() const { return list_of_node_level_configuration_structures_for_event_trigger; }
        ItemsElement & get_mutable_list_of_node_level_configuration_structures_for_event_trigger() { return list_of_node_level_configuration_structures_for_event_trigger; }
        void set_list_of_node_level_configuration_structures_for_event_trigger(const ItemsElement & value) { this->list_of_node_level_configuration_structures_for_event_trigger = value; }
    };

    class E2SmCccEventTriggerDefinitionFormat1 {
        public:
        E2SmCccEventTriggerDefinitionFormat1() = default;
        virtual ~E2SmCccEventTriggerDefinitionFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccEventTriggerDefinitionFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccEventTriggerDefinitionFormat1Properties & get_properties() const { return properties; }
        E2SmCccEventTriggerDefinitionFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccEventTriggerDefinitionFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccEventTriggerDefinitionFormat2Properties {
        public:
        E2SmCccEventTriggerDefinitionFormat2Properties() = default;
        virtual ~E2SmCccEventTriggerDefinitionFormat2Properties() = default;

        private:
        ItemsElement list_of_cell_level_configuration_structures_for_event_trigger;

        public:
        const ItemsElement & get_list_of_cell_level_configuration_structures_for_event_trigger() const { return list_of_cell_level_configuration_structures_for_event_trigger; }
        ItemsElement & get_mutable_list_of_cell_level_configuration_structures_for_event_trigger() { return list_of_cell_level_configuration_structures_for_event_trigger; }
        void set_list_of_cell_level_configuration_structures_for_event_trigger(const ItemsElement & value) { this->list_of_cell_level_configuration_structures_for_event_trigger = value; }
    };

    class E2SmCccEventTriggerDefinitionFormat2 {
        public:
        E2SmCccEventTriggerDefinitionFormat2() = default;
        virtual ~E2SmCccEventTriggerDefinitionFormat2() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccEventTriggerDefinitionFormat2Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccEventTriggerDefinitionFormat2Properties & get_properties() const { return properties; }
        E2SmCccEventTriggerDefinitionFormat2Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccEventTriggerDefinitionFormat2Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccEventTriggerDefinitionFormat3Properties {
        public:
        E2SmCccEventTriggerDefinitionFormat3Properties() = default;
        virtual ~E2SmCccEventTriggerDefinitionFormat3Properties() = default;

        private:
        EutraCellIdentity period;

        public:
        const EutraCellIdentity & get_period() const { return period; }
        EutraCellIdentity & get_mutable_period() { return period; }
        void set_period(const EutraCellIdentity & value) { this->period = value; }
    };

    class E2SmCccEventTriggerDefinitionFormat3 {
        public:
        E2SmCccEventTriggerDefinitionFormat3() = default;
        virtual ~E2SmCccEventTriggerDefinitionFormat3() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccEventTriggerDefinitionFormat3Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccEventTriggerDefinitionFormat3Properties & get_properties() const { return properties; }
        E2SmCccEventTriggerDefinitionFormat3Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccEventTriggerDefinitionFormat3Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccIndicationHeaderFormat1Properties {
        public:
        E2SmCccIndicationHeaderFormat1Properties() = default;
        virtual ~E2SmCccIndicationHeaderFormat1Properties() = default;

        private:
        ChangeType indication_reason;
        EutraCellIdentity event_time;

        public:
        const ChangeType & get_indication_reason() const { return indication_reason; }
        ChangeType & get_mutable_indication_reason() { return indication_reason; }
        void set_indication_reason(const ChangeType & value) { this->indication_reason = value; }

        const EutraCellIdentity & get_event_time() const { return event_time; }
        EutraCellIdentity & get_mutable_event_time() { return event_time; }
        void set_event_time(const EutraCellIdentity & value) { this->event_time = value; }
    };

    class E2SmCccIndicationHeaderFormat1 {
        public:
        E2SmCccIndicationHeaderFormat1() = default;
        virtual ~E2SmCccIndicationHeaderFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccIndicationHeaderFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccIndicationHeaderFormat1Properties & get_properties() const { return properties; }
        E2SmCccIndicationHeaderFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccIndicationHeaderFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccIndicationMessageFormat1Properties {
        public:
        E2SmCccIndicationMessageFormat1Properties() = default;
        virtual ~E2SmCccIndicationMessageFormat1Properties() = default;

        private:
        ItemsElement list_of_configuration_structures_reported;

        public:
        const ItemsElement & get_list_of_configuration_structures_reported() const { return list_of_configuration_structures_reported; }
        ItemsElement & get_mutable_list_of_configuration_structures_reported() { return list_of_configuration_structures_reported; }
        void set_list_of_configuration_structures_reported(const ItemsElement & value) { this->list_of_configuration_structures_reported = value; }
    };

    class E2SmCccIndicationMessageFormat1 {
        public:
        E2SmCccIndicationMessageFormat1() = default;
        virtual ~E2SmCccIndicationMessageFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccIndicationMessageFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccIndicationMessageFormat1Properties & get_properties() const { return properties; }
        E2SmCccIndicationMessageFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccIndicationMessageFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccIndicationMessageFormat2Properties {
        public:
        E2SmCccIndicationMessageFormat2Properties() = default;
        virtual ~E2SmCccIndicationMessageFormat2Properties() = default;

        private:
        ItemsElement list_of_cells_reported;

        public:
        const ItemsElement & get_list_of_cells_reported() const { return list_of_cells_reported; }
        ItemsElement & get_mutable_list_of_cells_reported() { return list_of_cells_reported; }
        void set_list_of_cells_reported(const ItemsElement & value) { this->list_of_cells_reported = value; }
    };

    class E2SmCccIndicationMessageFormat2 {
        public:
        E2SmCccIndicationMessageFormat2() = default;
        virtual ~E2SmCccIndicationMessageFormat2() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccIndicationMessageFormat2Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccIndicationMessageFormat2Properties & get_properties() const { return properties; }
        E2SmCccIndicationMessageFormat2Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccIndicationMessageFormat2Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccQueryDefinitionFormat1Properties {
        public:
        E2SmCccQueryDefinitionFormat1Properties() = default;
        virtual ~E2SmCccQueryDefinitionFormat1Properties() = default;

        private:
        ItemsElement list_of_nodelevel_ran_configuration_structures_for_query;

        public:
        const ItemsElement & get_list_of_nodelevel_ran_configuration_structures_for_query() const { return list_of_nodelevel_ran_configuration_structures_for_query; }
        ItemsElement & get_mutable_list_of_nodelevel_ran_configuration_structures_for_query() { return list_of_nodelevel_ran_configuration_structures_for_query; }
        void set_list_of_nodelevel_ran_configuration_structures_for_query(const ItemsElement & value) { this->list_of_nodelevel_ran_configuration_structures_for_query = value; }
    };

    class E2SmCccQueryDefinitionFormat1 {
        public:
        E2SmCccQueryDefinitionFormat1() = default;
        virtual ~E2SmCccQueryDefinitionFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccQueryDefinitionFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccQueryDefinitionFormat1Properties & get_properties() const { return properties; }
        E2SmCccQueryDefinitionFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccQueryDefinitionFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccQueryDefinitionFormat2Properties {
        public:
        E2SmCccQueryDefinitionFormat2Properties() = default;
        virtual ~E2SmCccQueryDefinitionFormat2Properties() = default;

        private:
        ItemsElement list_of_cells_to_be_queried_for_query;

        public:
        const ItemsElement & get_list_of_cells_to_be_queried_for_query() const { return list_of_cells_to_be_queried_for_query; }
        ItemsElement & get_mutable_list_of_cells_to_be_queried_for_query() { return list_of_cells_to_be_queried_for_query; }
        void set_list_of_cells_to_be_queried_for_query(const ItemsElement & value) { this->list_of_cells_to_be_queried_for_query = value; }
    };

    class E2SmCccQueryDefinitionFormat2 {
        public:
        E2SmCccQueryDefinitionFormat2() = default;
        virtual ~E2SmCccQueryDefinitionFormat2() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccQueryDefinitionFormat2Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccQueryDefinitionFormat2Properties & get_properties() const { return properties; }
        E2SmCccQueryDefinitionFormat2Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccQueryDefinitionFormat2Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccQueryOutcomeFormat1Properties {
        public:
        E2SmCccQueryOutcomeFormat1Properties() = default;
        virtual ~E2SmCccQueryOutcomeFormat1Properties() = default;

        private:
        ItemsElement list_of_configuration_structures_to_be_reported_for_query;

        public:
        const ItemsElement & get_list_of_configuration_structures_to_be_reported_for_query() const { return list_of_configuration_structures_to_be_reported_for_query; }
        ItemsElement & get_mutable_list_of_configuration_structures_to_be_reported_for_query() { return list_of_configuration_structures_to_be_reported_for_query; }
        void set_list_of_configuration_structures_to_be_reported_for_query(const ItemsElement & value) { this->list_of_configuration_structures_to_be_reported_for_query = value; }
    };

    class E2SmCccQueryOutcomeFormat1 {
        public:
        E2SmCccQueryOutcomeFormat1() = default;
        virtual ~E2SmCccQueryOutcomeFormat1() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccQueryOutcomeFormat1Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccQueryOutcomeFormat1Properties & get_properties() const { return properties; }
        E2SmCccQueryOutcomeFormat1Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccQueryOutcomeFormat1Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class E2SmCccQueryOutcomeFormat2Properties {
        public:
        E2SmCccQueryOutcomeFormat2Properties() = default;
        virtual ~E2SmCccQueryOutcomeFormat2Properties() = default;

        private:
        ItemsElement list_of_cells_to_be_reported_for_query;

        public:
        const ItemsElement & get_list_of_cells_to_be_reported_for_query() const { return list_of_cells_to_be_reported_for_query; }
        ItemsElement & get_mutable_list_of_cells_to_be_reported_for_query() { return list_of_cells_to_be_reported_for_query; }
        void set_list_of_cells_to_be_reported_for_query(const ItemsElement & value) { this->list_of_cells_to_be_reported_for_query = value; }
    };

    class E2SmCccQueryOutcomeFormat2 {
        public:
        E2SmCccQueryOutcomeFormat2() = default;
        virtual ~E2SmCccQueryOutcomeFormat2() = default;

        private:
        EutraCellIdentityType type;
        E2SmCccQueryOutcomeFormat2Properties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const E2SmCccQueryOutcomeFormat2Properties & get_properties() const { return properties; }
        E2SmCccQueryOutcomeFormat2Properties & get_mutable_properties() { return properties; }
        void set_properties(const E2SmCccQueryOutcomeFormat2Properties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class EnergySavingCapabilityCommonInfoProperties {
        public:
        EnergySavingCapabilityCommonInfoProperties() = default;
        virtual ~EnergySavingCapabilityCommonInfoProperties() = default;

        private:
        EutraCellIdentity st8_ready_message_supported;
        EutraCellIdentity sleep_duration_extension_supported;
        EutraCellIdentity emergency_wake_up_command_supported;

        public:
        const EutraCellIdentity & get_st8_ready_message_supported() const { return st8_ready_message_supported; }
        EutraCellIdentity & get_mutable_st8_ready_message_supported() { return st8_ready_message_supported; }
        void set_st8_ready_message_supported(const EutraCellIdentity & value) { this->st8_ready_message_supported = value; }

        const EutraCellIdentity & get_sleep_duration_extension_supported() const { return sleep_duration_extension_supported; }
        EutraCellIdentity & get_mutable_sleep_duration_extension_supported() { return sleep_duration_extension_supported; }
        void set_sleep_duration_extension_supported(const EutraCellIdentity & value) { this->sleep_duration_extension_supported = value; }

        const EutraCellIdentity & get_emergency_wake_up_command_supported() const { return emergency_wake_up_command_supported; }
        EutraCellIdentity & get_mutable_emergency_wake_up_command_supported() { return emergency_wake_up_command_supported; }
        void set_emergency_wake_up_command_supported(const EutraCellIdentity & value) { this->emergency_wake_up_command_supported = value; }
    };

    class EnergySavingCapabilityCommonInfo {
        public:
        EnergySavingCapabilityCommonInfo() = default;
        virtual ~EnergySavingCapabilityCommonInfo() = default;

        private:
        EutraCellIdentityType type;
        EnergySavingCapabilityCommonInfoProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const EnergySavingCapabilityCommonInfoProperties & get_properties() const { return properties; }
        EnergySavingCapabilityCommonInfoProperties & get_mutable_properties() { return properties; }
        void set_properties(const EnergySavingCapabilityCommonInfoProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class OneOfProperties {
        public:
        OneOfProperties() = default;
        virtual ~OneOfProperties() = default;

        private:
        boost::optional<EutraCellIdentity> target_ec;
        boost::optional<GnbCuUpId> es_percentage;

        public:
        boost::optional<EutraCellIdentity> get_target_ec() const { return target_ec; }
        void set_target_ec(boost::optional<EutraCellIdentity> value) { this->target_ec = value; }

        boost::optional<GnbCuUpId> get_es_percentage() const { return es_percentage; }
        void set_es_percentage(boost::optional<GnbCuUpId> value) { this->es_percentage = value; }
    };

    class OneOf {
        public:
        OneOf() = default;
        virtual ~OneOf() = default;

        private:
        EutraCellIdentityType type;
        OneOfProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const OneOfProperties & get_properties() const { return properties; }
        OneOfProperties & get_mutable_properties() { return properties; }
        void set_properties(const OneOfProperties & value) { this->properties = value; }
    };

    class EsObjective {
        public:
        EsObjective() = default;
        virtual ~EsObjective() = default;

        private:
        std::vector<OneOf> one_of;

        public:
        const std::vector<OneOf> & get_one_of() const { return one_of; }
        std::vector<OneOf> & get_mutable_one_of() { return one_of; }
        void set_one_of(const std::vector<OneOf> & value) { this->one_of = value; }
    };

    class EutraCgiProperties {
        public:
        EutraCgiProperties() = default;
        virtual ~EutraCgiProperties() = default;

        private:
        ItemsElement plmn_identity;
        ItemsElement e_utra_cell_identity;

        public:
        const ItemsElement & get_plmn_identity() const { return plmn_identity; }
        ItemsElement & get_mutable_plmn_identity() { return plmn_identity; }
        void set_plmn_identity(const ItemsElement & value) { this->plmn_identity = value; }

        const ItemsElement & get_e_utra_cell_identity() const { return e_utra_cell_identity; }
        ItemsElement & get_mutable_e_utra_cell_identity() { return e_utra_cell_identity; }
        void set_e_utra_cell_identity(const ItemsElement & value) { this->e_utra_cell_identity = value; }
    };

    class EutraCgi {
        public:
        EutraCgi() = default;
        virtual ~EutraCgi() = default;

        private:
        EutraCellIdentityType type;
        EutraCgiProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const EutraCgiProperties & get_properties() const { return properties; }
        EutraCgiProperties & get_mutable_properties() { return properties; }
        void set_properties(const EutraCgiProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class EventTriggerProperties {
        public:
        EventTriggerProperties() = default;
        virtual ~EventTriggerProperties() = default;

        private:
        ItemsElement list_of_supported_event_trigger_styles;

        public:
        const ItemsElement & get_list_of_supported_event_trigger_styles() const { return list_of_supported_event_trigger_styles; }
        ItemsElement & get_mutable_list_of_supported_event_trigger_styles() { return list_of_supported_event_trigger_styles; }
        void set_list_of_supported_event_trigger_styles(const ItemsElement & value) { this->list_of_supported_event_trigger_styles = value; }
    };

    class EventTrigger {
        public:
        EventTrigger() = default;
        virtual ~EventTrigger() = default;

        private:
        EutraCellIdentityType type;
        EventTriggerProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const EventTriggerProperties & get_properties() const { return properties; }
        EventTriggerProperties & get_mutable_properties() { return properties; }
        void set_properties(const EventTriggerProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class EventTriggerStyleProperties {
        public:
        EventTriggerStyleProperties() = default;
        virtual ~EventTriggerStyleProperties() = default;

        private:
        EutraCellIdentity event_trigger_style_type;
        EutraCellIdentity event_trigger_style_name;
        EutraCellIdentity event_trigger_format_type;

        public:
        const EutraCellIdentity & get_event_trigger_style_type() const { return event_trigger_style_type; }
        EutraCellIdentity & get_mutable_event_trigger_style_type() { return event_trigger_style_type; }
        void set_event_trigger_style_type(const EutraCellIdentity & value) { this->event_trigger_style_type = value; }

        const EutraCellIdentity & get_event_trigger_style_name() const { return event_trigger_style_name; }
        EutraCellIdentity & get_mutable_event_trigger_style_name() { return event_trigger_style_name; }
        void set_event_trigger_style_name(const EutraCellIdentity & value) { this->event_trigger_style_name = value; }

        const EutraCellIdentity & get_event_trigger_format_type() const { return event_trigger_format_type; }
        EutraCellIdentity & get_mutable_event_trigger_format_type() { return event_trigger_format_type; }
        void set_event_trigger_format_type(const EutraCellIdentity & value) { this->event_trigger_format_type = value; }
    };

    class EventTriggerStyle {
        public:
        EventTriggerStyle() = default;
        virtual ~EventTriggerStyle() = default;

        private:
        EutraCellIdentityType type;
        EventTriggerStyleProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const EventTriggerStyleProperties & get_properties() const { return properties; }
        EventTriggerStyleProperties & get_mutable_properties() { return properties; }
        void set_properties(const EventTriggerStyleProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class EventTriggerStyleTypeProperties {
        public:
        EventTriggerStyleTypeProperties() = default;
        virtual ~EventTriggerStyleTypeProperties() = default;

        private:
        EutraCellIdentity event_trigger_style_type;

        public:
        const EutraCellIdentity & get_event_trigger_style_type() const { return event_trigger_style_type; }
        EutraCellIdentity & get_mutable_event_trigger_style_type() { return event_trigger_style_type; }
        void set_event_trigger_style_type(const EutraCellIdentity & value) { this->event_trigger_style_type = value; }
    };

    class EventTriggerStyleType {
        public:
        EventTriggerStyleType() = default;
        virtual ~EventTriggerStyleType() = default;

        private:
        EutraCellIdentityType type;
        EventTriggerStyleTypeProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const EventTriggerStyleTypeProperties & get_properties() const { return properties; }
        EventTriggerStyleTypeProperties & get_mutable_properties() { return properties; }
        void set_properties(const EventTriggerStyleTypeProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class GEnbId {
        public:
        GEnbId() = default;
        virtual ~GEnbId() = default;

        private:
        EutraCellIdentityType type;
        std::string pattern;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const std::string & get_pattern() const { return pattern; }
        std::string & get_mutable_pattern() { return pattern; }
        void set_pattern(const std::string & value) { this->pattern = value; }
    };

    class GnbName {
        public:
        GnbName() = default;
        virtual ~GnbName() = default;

        private:
        EutraCellIdentityType type;
        int64_t max_length;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const int64_t & get_max_length() const { return max_length; }
        int64_t & get_mutable_max_length() { return max_length; }
        void set_max_length(const int64_t & value) { this->max_length = value; }
    };

    class NrCgiProperties {
        public:
        NrCgiProperties() = default;
        virtual ~NrCgiProperties() = default;

        private:
        ItemsElement plmn_identity;
        ItemsElement n_r_cell_identity;

        public:
        const ItemsElement & get_plmn_identity() const { return plmn_identity; }
        ItemsElement & get_mutable_plmn_identity() { return plmn_identity; }
        void set_plmn_identity(const ItemsElement & value) { this->plmn_identity = value; }

        const ItemsElement & get_n_r_cell_identity() const { return n_r_cell_identity; }
        ItemsElement & get_mutable_n_r_cell_identity() { return n_r_cell_identity; }
        void set_n_r_cell_identity(const ItemsElement & value) { this->n_r_cell_identity = value; }
    };

    class NrCgi {
        public:
        NrCgi() = default;
        virtual ~NrCgi() = default;

        private:
        EutraCellIdentityType type;
        NrCgiProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const NrCgiProperties & get_properties() const { return properties; }
        NrCgiProperties & get_mutable_properties() { return properties; }
        void set_properties(const NrCgiProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class OBwpProperties {
        public:
        OBwpProperties() = default;
        virtual ~OBwpProperties() = default;

        private:
        ItemsElement bwp_context;
        ItemsElement is_initial_bwp;
        ItemsElement sub_carrier_spacing;
        ItemsElement cyclic_prefix;
        EutraCellIdentity start_rb;
        EutraCellIdentity number_of_r_bs;

        public:
        const ItemsElement & get_bwp_context() const { return bwp_context; }
        ItemsElement & get_mutable_bwp_context() { return bwp_context; }
        void set_bwp_context(const ItemsElement & value) { this->bwp_context = value; }

        const ItemsElement & get_is_initial_bwp() const { return is_initial_bwp; }
        ItemsElement & get_mutable_is_initial_bwp() { return is_initial_bwp; }
        void set_is_initial_bwp(const ItemsElement & value) { this->is_initial_bwp = value; }

        const ItemsElement & get_sub_carrier_spacing() const { return sub_carrier_spacing; }
        ItemsElement & get_mutable_sub_carrier_spacing() { return sub_carrier_spacing; }
        void set_sub_carrier_spacing(const ItemsElement & value) { this->sub_carrier_spacing = value; }

        const ItemsElement & get_cyclic_prefix() const { return cyclic_prefix; }
        ItemsElement & get_mutable_cyclic_prefix() { return cyclic_prefix; }
        void set_cyclic_prefix(const ItemsElement & value) { this->cyclic_prefix = value; }

        const EutraCellIdentity & get_start_rb() const { return start_rb; }
        EutraCellIdentity & get_mutable_start_rb() { return start_rb; }
        void set_start_rb(const EutraCellIdentity & value) { this->start_rb = value; }

        const EutraCellIdentity & get_number_of_r_bs() const { return number_of_r_bs; }
        EutraCellIdentity & get_mutable_number_of_r_bs() { return number_of_r_bs; }
        void set_number_of_r_bs(const EutraCellIdentity & value) { this->number_of_r_bs = value; }
    };

    class OBwp {
        public:
        OBwp() = default;
        virtual ~OBwp() = default;

        private:
        EutraCellIdentityType type;
        OBwpProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const OBwpProperties & get_properties() const { return properties; }
        OBwpProperties & get_mutable_properties() { return properties; }
        void set_properties(const OBwpProperties & value) { this->properties = value; }
    };

    class OCellDtxdrxConfigProperties {
        public:
        OCellDtxdrxConfigProperties() = default;
        virtual ~OCellDtxdrxConfigProperties() = default;

        private:
        ItemsElement on_duration_timer;
        ItemsElement cycle_start_offset;
        GnbCuUpId slot_offset;
        AdministrativeState config_type;
        AdministrativeState activation_status;
        AdministrativeState l1_activation;

        public:
        const ItemsElement & get_on_duration_timer() const { return on_duration_timer; }
        ItemsElement & get_mutable_on_duration_timer() { return on_duration_timer; }
        void set_on_duration_timer(const ItemsElement & value) { this->on_duration_timer = value; }

        const ItemsElement & get_cycle_start_offset() const { return cycle_start_offset; }
        ItemsElement & get_mutable_cycle_start_offset() { return cycle_start_offset; }
        void set_cycle_start_offset(const ItemsElement & value) { this->cycle_start_offset = value; }

        const GnbCuUpId & get_slot_offset() const { return slot_offset; }
        GnbCuUpId & get_mutable_slot_offset() { return slot_offset; }
        void set_slot_offset(const GnbCuUpId & value) { this->slot_offset = value; }

        const AdministrativeState & get_config_type() const { return config_type; }
        AdministrativeState & get_mutable_config_type() { return config_type; }
        void set_config_type(const AdministrativeState & value) { this->config_type = value; }

        const AdministrativeState & get_activation_status() const { return activation_status; }
        AdministrativeState & get_mutable_activation_status() { return activation_status; }
        void set_activation_status(const AdministrativeState & value) { this->activation_status = value; }

        const AdministrativeState & get_l1_activation() const { return l1_activation; }
        AdministrativeState & get_mutable_l1_activation() { return l1_activation; }
        void set_l1_activation(const AdministrativeState & value) { this->l1_activation = value; }
    };

    class OCellDtxdrxConfig {
        public:
        OCellDtxdrxConfig() = default;
        virtual ~OCellDtxdrxConfig() = default;

        private:
        EutraCellIdentityType type;
        OCellDtxdrxConfigProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const OCellDtxdrxConfigProperties & get_properties() const { return properties; }
        OCellDtxdrxConfigProperties & get_mutable_properties() { return properties; }
        void set_properties(const OCellDtxdrxConfigProperties & value) { this->properties = value; }
    };

    class OCesManagementFunctionProperties {
        public:
        OCesManagementFunctionProperties() = default;
        virtual ~OCesManagementFunctionProperties() = default;

        private:
        EutraCellIdentity ces_switch;
        AdministrativeState energy_saving_state;
        AdministrativeState energy_saving_control;

        public:
        const EutraCellIdentity & get_ces_switch() const { return ces_switch; }
        EutraCellIdentity & get_mutable_ces_switch() { return ces_switch; }
        void set_ces_switch(const EutraCellIdentity & value) { this->ces_switch = value; }

        const AdministrativeState & get_energy_saving_state() const { return energy_saving_state; }
        AdministrativeState & get_mutable_energy_saving_state() { return energy_saving_state; }
        void set_energy_saving_state(const AdministrativeState & value) { this->energy_saving_state = value; }

        const AdministrativeState & get_energy_saving_control() const { return energy_saving_control; }
        AdministrativeState & get_mutable_energy_saving_control() { return energy_saving_control; }
        void set_energy_saving_control(const AdministrativeState & value) { this->energy_saving_control = value; }
    };

    class OCesManagementFunction {
        public:
        OCesManagementFunction() = default;
        virtual ~OCesManagementFunction() = default;

        private:
        EutraCellIdentityType type;
        OCesManagementFunctionProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const OCesManagementFunctionProperties & get_properties() const { return properties; }
        OCesManagementFunctionProperties & get_mutable_properties() { return properties; }
        void set_properties(const OCesManagementFunctionProperties & value) { this->properties = value; }
    };

    class OGnbCuCpFunction {
        public:
        OGnbCuCpFunction() = default;
        virtual ~OGnbCuCpFunction() = default;

        private:
        EutraCellIdentityType type;
        std::map<std::string, ItemsElement> properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const std::map<std::string, ItemsElement> & get_properties() const { return properties; }
        std::map<std::string, ItemsElement> & get_mutable_properties() { return properties; }
        void set_properties(const std::map<std::string, ItemsElement> & value) { this->properties = value; }
    };

    class ONesPolicyProperties {
        public:
        ONesPolicyProperties() = default;
        virtual ~ONesPolicyProperties() = default;

        private:
        AdministrativeState policy_type;
        EutraCellIdentity antenna_mask_name;
        EutraCellIdentity antenna_mask;
        AdministrativeState sleep_mode;
        AdministrativeState data_dir;
        GnbCuUpId symbol_mask;
        EutraCellIdentity slot_mask;
        EutraCellIdentity valid_duration;
        ItemsElement es_objective;
        ItemsElement perf_objective_list;

        public:
        const AdministrativeState & get_policy_type() const { return policy_type; }
        AdministrativeState & get_mutable_policy_type() { return policy_type; }
        void set_policy_type(const AdministrativeState & value) { this->policy_type = value; }

        const EutraCellIdentity & get_antenna_mask_name() const { return antenna_mask_name; }
        EutraCellIdentity & get_mutable_antenna_mask_name() { return antenna_mask_name; }
        void set_antenna_mask_name(const EutraCellIdentity & value) { this->antenna_mask_name = value; }

        const EutraCellIdentity & get_antenna_mask() const { return antenna_mask; }
        EutraCellIdentity & get_mutable_antenna_mask() { return antenna_mask; }
        void set_antenna_mask(const EutraCellIdentity & value) { this->antenna_mask = value; }

        const AdministrativeState & get_sleep_mode() const { return sleep_mode; }
        AdministrativeState & get_mutable_sleep_mode() { return sleep_mode; }
        void set_sleep_mode(const AdministrativeState & value) { this->sleep_mode = value; }

        const AdministrativeState & get_data_dir() const { return data_dir; }
        AdministrativeState & get_mutable_data_dir() { return data_dir; }
        void set_data_dir(const AdministrativeState & value) { this->data_dir = value; }

        const GnbCuUpId & get_symbol_mask() const { return symbol_mask; }
        GnbCuUpId & get_mutable_symbol_mask() { return symbol_mask; }
        void set_symbol_mask(const GnbCuUpId & value) { this->symbol_mask = value; }

        const EutraCellIdentity & get_slot_mask() const { return slot_mask; }
        EutraCellIdentity & get_mutable_slot_mask() { return slot_mask; }
        void set_slot_mask(const EutraCellIdentity & value) { this->slot_mask = value; }

        const EutraCellIdentity & get_valid_duration() const { return valid_duration; }
        EutraCellIdentity & get_mutable_valid_duration() { return valid_duration; }
        void set_valid_duration(const EutraCellIdentity & value) { this->valid_duration = value; }

        const ItemsElement & get_es_objective() const { return es_objective; }
        ItemsElement & get_mutable_es_objective() { return es_objective; }
        void set_es_objective(const ItemsElement & value) { this->es_objective = value; }

        const ItemsElement & get_perf_objective_list() const { return perf_objective_list; }
        ItemsElement & get_mutable_perf_objective_list() { return perf_objective_list; }
        void set_perf_objective_list(const ItemsElement & value) { this->perf_objective_list = value; }
    };

    class ONesPolicy {
        public:
        ONesPolicy() = default;
        virtual ~ONesPolicy() = default;

        private:
        EutraCellIdentityType type;
        ONesPolicyProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ONesPolicyProperties & get_properties() const { return properties; }
        ONesPolicyProperties & get_mutable_properties() { return properties; }
        void set_properties(const ONesPolicyProperties & value) { this->properties = value; }
    };

    class ONrCellCuProperties {
        public:
        ONrCellCuProperties() = default;
        virtual ~ONrCellCuProperties() = default;

        private:
        EutraCellIdentity cell_local_id;
        ItemsElement plmn_info_list;

        public:
        const EutraCellIdentity & get_cell_local_id() const { return cell_local_id; }
        EutraCellIdentity & get_mutable_cell_local_id() { return cell_local_id; }
        void set_cell_local_id(const EutraCellIdentity & value) { this->cell_local_id = value; }

        const ItemsElement & get_plmn_info_list() const { return plmn_info_list; }
        ItemsElement & get_mutable_plmn_info_list() { return plmn_info_list; }
        void set_plmn_info_list(const ItemsElement & value) { this->plmn_info_list = value; }
    };

    class ONrCellCu {
        public:
        ONrCellCu() = default;
        virtual ~ONrCellCu() = default;

        private:
        EutraCellIdentityType type;
        ONrCellCuProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ONrCellCuProperties & get_properties() const { return properties; }
        ONrCellCuProperties & get_mutable_properties() { return properties; }
        void set_properties(const ONrCellCuProperties & value) { this->properties = value; }
    };

    class ONrCellDuProperties {
        public:
        ONrCellDuProperties() = default;
        virtual ~ONrCellDuProperties() = default;

        private:
        EutraCellIdentity cell_local_id;
        ItemsElement operational_state;
        ItemsElement administrative_state;
        ItemsElement cell_state;
        ItemsElement plmn_info_list;
        ItemsElement nr_pci;
        ItemsElement nr_tac;
        EutraCellIdentity arfcn_dl;
        EutraCellIdentity arfcn_ul;
        EutraCellIdentity arfcn_sul;
        EutraCellIdentity b_s_channel_bw_dl;
        GnbCuUpId ssb_frequency;
        ItemsElement ssb_periodicity;
        ItemsElement ssb_sub_carrier_spacing;
        GnbCuUpId ssb_offset;
        ItemsElement ssb_duration;
        EutraCellIdentity b_s_channel_bw_ul;
        EutraCellIdentity b_s_channel_bw_sul;
        GEnbIdList bwp_list;
        ItemsElement partition_list;

        public:
        const EutraCellIdentity & get_cell_local_id() const { return cell_local_id; }
        EutraCellIdentity & get_mutable_cell_local_id() { return cell_local_id; }
        void set_cell_local_id(const EutraCellIdentity & value) { this->cell_local_id = value; }

        const ItemsElement & get_operational_state() const { return operational_state; }
        ItemsElement & get_mutable_operational_state() { return operational_state; }
        void set_operational_state(const ItemsElement & value) { this->operational_state = value; }

        const ItemsElement & get_administrative_state() const { return administrative_state; }
        ItemsElement & get_mutable_administrative_state() { return administrative_state; }
        void set_administrative_state(const ItemsElement & value) { this->administrative_state = value; }

        const ItemsElement & get_cell_state() const { return cell_state; }
        ItemsElement & get_mutable_cell_state() { return cell_state; }
        void set_cell_state(const ItemsElement & value) { this->cell_state = value; }

        const ItemsElement & get_plmn_info_list() const { return plmn_info_list; }
        ItemsElement & get_mutable_plmn_info_list() { return plmn_info_list; }
        void set_plmn_info_list(const ItemsElement & value) { this->plmn_info_list = value; }

        const ItemsElement & get_nr_pci() const { return nr_pci; }
        ItemsElement & get_mutable_nr_pci() { return nr_pci; }
        void set_nr_pci(const ItemsElement & value) { this->nr_pci = value; }

        const ItemsElement & get_nr_tac() const { return nr_tac; }
        ItemsElement & get_mutable_nr_tac() { return nr_tac; }
        void set_nr_tac(const ItemsElement & value) { this->nr_tac = value; }

        const EutraCellIdentity & get_arfcn_dl() const { return arfcn_dl; }
        EutraCellIdentity & get_mutable_arfcn_dl() { return arfcn_dl; }
        void set_arfcn_dl(const EutraCellIdentity & value) { this->arfcn_dl = value; }

        const EutraCellIdentity & get_arfcn_ul() const { return arfcn_ul; }
        EutraCellIdentity & get_mutable_arfcn_ul() { return arfcn_ul; }
        void set_arfcn_ul(const EutraCellIdentity & value) { this->arfcn_ul = value; }

        const EutraCellIdentity & get_arfcn_sul() const { return arfcn_sul; }
        EutraCellIdentity & get_mutable_arfcn_sul() { return arfcn_sul; }
        void set_arfcn_sul(const EutraCellIdentity & value) { this->arfcn_sul = value; }

        const EutraCellIdentity & get_b_s_channel_bw_dl() const { return b_s_channel_bw_dl; }
        EutraCellIdentity & get_mutable_b_s_channel_bw_dl() { return b_s_channel_bw_dl; }
        void set_b_s_channel_bw_dl(const EutraCellIdentity & value) { this->b_s_channel_bw_dl = value; }

        const GnbCuUpId & get_ssb_frequency() const { return ssb_frequency; }
        GnbCuUpId & get_mutable_ssb_frequency() { return ssb_frequency; }
        void set_ssb_frequency(const GnbCuUpId & value) { this->ssb_frequency = value; }

        const ItemsElement & get_ssb_periodicity() const { return ssb_periodicity; }
        ItemsElement & get_mutable_ssb_periodicity() { return ssb_periodicity; }
        void set_ssb_periodicity(const ItemsElement & value) { this->ssb_periodicity = value; }

        const ItemsElement & get_ssb_sub_carrier_spacing() const { return ssb_sub_carrier_spacing; }
        ItemsElement & get_mutable_ssb_sub_carrier_spacing() { return ssb_sub_carrier_spacing; }
        void set_ssb_sub_carrier_spacing(const ItemsElement & value) { this->ssb_sub_carrier_spacing = value; }

        const GnbCuUpId & get_ssb_offset() const { return ssb_offset; }
        GnbCuUpId & get_mutable_ssb_offset() { return ssb_offset; }
        void set_ssb_offset(const GnbCuUpId & value) { this->ssb_offset = value; }

        const ItemsElement & get_ssb_duration() const { return ssb_duration; }
        ItemsElement & get_mutable_ssb_duration() { return ssb_duration; }
        void set_ssb_duration(const ItemsElement & value) { this->ssb_duration = value; }

        const EutraCellIdentity & get_b_s_channel_bw_ul() const { return b_s_channel_bw_ul; }
        EutraCellIdentity & get_mutable_b_s_channel_bw_ul() { return b_s_channel_bw_ul; }
        void set_b_s_channel_bw_ul(const EutraCellIdentity & value) { this->b_s_channel_bw_ul = value; }

        const EutraCellIdentity & get_b_s_channel_bw_sul() const { return b_s_channel_bw_sul; }
        EutraCellIdentity & get_mutable_b_s_channel_bw_sul() { return b_s_channel_bw_sul; }
        void set_b_s_channel_bw_sul(const EutraCellIdentity & value) { this->b_s_channel_bw_sul = value; }

        const GEnbIdList & get_bwp_list() const { return bwp_list; }
        GEnbIdList & get_mutable_bwp_list() { return bwp_list; }
        void set_bwp_list(const GEnbIdList & value) { this->bwp_list = value; }

        const ItemsElement & get_partition_list() const { return partition_list; }
        ItemsElement & get_mutable_partition_list() { return partition_list; }
        void set_partition_list(const ItemsElement & value) { this->partition_list = value; }
    };

    class ONrCellDu {
        public:
        ONrCellDu() = default;
        virtual ~ONrCellDu() = default;

        private:
        EutraCellIdentityType type;
        ONrCellDuProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ONrCellDuProperties & get_properties() const { return properties; }
        ONrCellDuProperties & get_mutable_properties() { return properties; }
        void set_properties(const ONrCellDuProperties & value) { this->properties = value; }
    };

    class OPrbBlankingPolicyProperties {
        public:
        OPrbBlankingPolicyProperties() = default;
        virtual ~OPrbBlankingPolicyProperties() = default;

        private:
        AdministrativeState policy_category;
        AdministrativeState link_dir;
        EutraCellIdentity start_time;
        EutraCellIdentity end_time;
        ItemsElement prb_blanking_configuration_list;
        EutraCellIdentity prb_blanking_obj;

        public:
        const AdministrativeState & get_policy_category() const { return policy_category; }
        AdministrativeState & get_mutable_policy_category() { return policy_category; }
        void set_policy_category(const AdministrativeState & value) { this->policy_category = value; }

        const AdministrativeState & get_link_dir() const { return link_dir; }
        AdministrativeState & get_mutable_link_dir() { return link_dir; }
        void set_link_dir(const AdministrativeState & value) { this->link_dir = value; }

        const EutraCellIdentity & get_start_time() const { return start_time; }
        EutraCellIdentity & get_mutable_start_time() { return start_time; }
        void set_start_time(const EutraCellIdentity & value) { this->start_time = value; }

        const EutraCellIdentity & get_end_time() const { return end_time; }
        EutraCellIdentity & get_mutable_end_time() { return end_time; }
        void set_end_time(const EutraCellIdentity & value) { this->end_time = value; }

        const ItemsElement & get_prb_blanking_configuration_list() const { return prb_blanking_configuration_list; }
        ItemsElement & get_mutable_prb_blanking_configuration_list() { return prb_blanking_configuration_list; }
        void set_prb_blanking_configuration_list(const ItemsElement & value) { this->prb_blanking_configuration_list = value; }

        const EutraCellIdentity & get_prb_blanking_obj() const { return prb_blanking_obj; }
        EutraCellIdentity & get_mutable_prb_blanking_obj() { return prb_blanking_obj; }
        void set_prb_blanking_obj(const EutraCellIdentity & value) { this->prb_blanking_obj = value; }
    };

    class OPrbBlankingPolicy {
        public:
        OPrbBlankingPolicy() = default;
        virtual ~OPrbBlankingPolicy() = default;

        private:
        EutraCellIdentityType type;
        OPrbBlankingPolicyProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const OPrbBlankingPolicyProperties & get_properties() const { return properties; }
        OPrbBlankingPolicyProperties & get_mutable_properties() { return properties; }
        void set_properties(const OPrbBlankingPolicyProperties & value) { this->properties = value; }
    };

    class ORrmPolicyRatioProperties {
        public:
        ORrmPolicyRatioProperties() = default;
        virtual ~ORrmPolicyRatioProperties() = default;

        private:
        ItemsElement resource_type;
        ItemsElement r_rm_policy_member_list;
        EutraCellIdentity r_rm_policy_max_ratio;
        EutraCellIdentity r_rm_policy_min_ratio;
        EutraCellIdentity r_rm_policy_dedicated_ratio;

        public:
        const ItemsElement & get_resource_type() const { return resource_type; }
        ItemsElement & get_mutable_resource_type() { return resource_type; }
        void set_resource_type(const ItemsElement & value) { this->resource_type = value; }

        const ItemsElement & get_r_rm_policy_member_list() const { return r_rm_policy_member_list; }
        ItemsElement & get_mutable_r_rm_policy_member_list() { return r_rm_policy_member_list; }
        void set_r_rm_policy_member_list(const ItemsElement & value) { this->r_rm_policy_member_list = value; }

        const EutraCellIdentity & get_r_rm_policy_max_ratio() const { return r_rm_policy_max_ratio; }
        EutraCellIdentity & get_mutable_r_rm_policy_max_ratio() { return r_rm_policy_max_ratio; }
        void set_r_rm_policy_max_ratio(const EutraCellIdentity & value) { this->r_rm_policy_max_ratio = value; }

        const EutraCellIdentity & get_r_rm_policy_min_ratio() const { return r_rm_policy_min_ratio; }
        EutraCellIdentity & get_mutable_r_rm_policy_min_ratio() { return r_rm_policy_min_ratio; }
        void set_r_rm_policy_min_ratio(const EutraCellIdentity & value) { this->r_rm_policy_min_ratio = value; }

        const EutraCellIdentity & get_r_rm_policy_dedicated_ratio() const { return r_rm_policy_dedicated_ratio; }
        EutraCellIdentity & get_mutable_r_rm_policy_dedicated_ratio() { return r_rm_policy_dedicated_ratio; }
        void set_r_rm_policy_dedicated_ratio(const EutraCellIdentity & value) { this->r_rm_policy_dedicated_ratio = value; }
    };

    class ORrmPolicyRatio {
        public:
        ORrmPolicyRatio() = default;
        virtual ~ORrmPolicyRatio() = default;

        private:
        EutraCellIdentityType type;
        ORrmPolicyRatioProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ORrmPolicyRatioProperties & get_properties() const { return properties; }
        ORrmPolicyRatioProperties & get_mutable_properties() { return properties; }
        void set_properties(const ORrmPolicyRatioProperties & value) { this->properties = value; }
    };

    class ORuInfoProperties {
        public:
        ORuInfoProperties() = default;
        virtual ~ORuInfoProperties() = default;

        private:
        ItemsElement oru_user_plane_configuration;
        ItemsElement oru_capabilities;

        public:
        const ItemsElement & get_oru_user_plane_configuration() const { return oru_user_plane_configuration; }
        ItemsElement & get_mutable_oru_user_plane_configuration() { return oru_user_plane_configuration; }
        void set_oru_user_plane_configuration(const ItemsElement & value) { this->oru_user_plane_configuration = value; }

        const ItemsElement & get_oru_capabilities() const { return oru_capabilities; }
        ItemsElement & get_mutable_oru_capabilities() { return oru_capabilities; }
        void set_oru_capabilities(const ItemsElement & value) { this->oru_capabilities = value; }
    };

    class ORuInfo {
        public:
        ORuInfo() = default;
        virtual ~ORuInfo() = default;

        private:
        EutraCellIdentityType type;
        ORuInfoProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ORuInfoProperties & get_properties() const { return properties; }
        ORuInfoProperties & get_mutable_properties() { return properties; }
        void set_properties(const ORuInfoProperties & value) { this->properties = value; }
    };

    class OnDurationTimer {
        public:
        OnDurationTimer() = default;
        virtual ~OnDurationTimer() = default;

        private:
        std::vector<GnbCuUpId> one_of;

        public:
        const std::vector<GnbCuUpId> & get_one_of() const { return one_of; }
        std::vector<GnbCuUpId> & get_mutable_one_of() { return one_of; }
        void set_one_of(const std::vector<GnbCuUpId> & value) { this->one_of = value; }
    };

    class OruCapabilitiesProperties {
        public:
        OruCapabilitiesProperties() = default;
        virtual ~OruCapabilitiesProperties() = default;

        private:
        ItemsElement energy_saving_capability_common_info;
        ItemsElement asm_capability_info;
        ItemsElement trx_control_capability_info;

        public:
        const ItemsElement & get_energy_saving_capability_common_info() const { return energy_saving_capability_common_info; }
        ItemsElement & get_mutable_energy_saving_capability_common_info() { return energy_saving_capability_common_info; }
        void set_energy_saving_capability_common_info(const ItemsElement & value) { this->energy_saving_capability_common_info = value; }

        const ItemsElement & get_asm_capability_info() const { return asm_capability_info; }
        ItemsElement & get_mutable_asm_capability_info() { return asm_capability_info; }
        void set_asm_capability_info(const ItemsElement & value) { this->asm_capability_info = value; }

        const ItemsElement & get_trx_control_capability_info() const { return trx_control_capability_info; }
        ItemsElement & get_mutable_trx_control_capability_info() { return trx_control_capability_info; }
        void set_trx_control_capability_info(const ItemsElement & value) { this->trx_control_capability_info = value; }
    };

    class OruCapabilities {
        public:
        OruCapabilities() = default;
        virtual ~OruCapabilities() = default;

        private:
        EutraCellIdentityType type;
        OruCapabilitiesProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const OruCapabilitiesProperties & get_properties() const { return properties; }
        OruCapabilitiesProperties & get_mutable_properties() { return properties; }
        void set_properties(const OruCapabilitiesProperties & value) { this->properties = value; }
    };

    class OruUserPlaneConfigurationProperties {
        public:
        OruUserPlaneConfigurationProperties() = default;
        virtual ~OruUserPlaneConfigurationProperties() = default;

        private:
        ItemsElement tx_array_list;
        ItemsElement rx_array_list;

        public:
        const ItemsElement & get_tx_array_list() const { return tx_array_list; }
        ItemsElement & get_mutable_tx_array_list() { return tx_array_list; }
        void set_tx_array_list(const ItemsElement & value) { this->tx_array_list = value; }

        const ItemsElement & get_rx_array_list() const { return rx_array_list; }
        ItemsElement & get_mutable_rx_array_list() { return rx_array_list; }
        void set_rx_array_list(const ItemsElement & value) { this->rx_array_list = value; }
    };

    class OruUserPlaneConfiguration {
        public:
        OruUserPlaneConfiguration() = default;
        virtual ~OruUserPlaneConfiguration() = default;

        private:
        EutraCellIdentityType type;
        OruUserPlaneConfigurationProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const OruUserPlaneConfigurationProperties & get_properties() const { return properties; }
        OruUserPlaneConfigurationProperties & get_mutable_properties() { return properties; }
        void set_properties(const OruUserPlaneConfigurationProperties & value) { this->properties = value; }
    };

    class PurpleProperties {
        public:
        PurpleProperties() = default;
        virtual ~PurpleProperties() = default;

        private:
        ItemsElement snssai;
        ItemsElement plmn_id;
        ItemsElement the_5_qi_list;

        public:
        const ItemsElement & get_snssai() const { return snssai; }
        ItemsElement & get_mutable_snssai() { return snssai; }
        void set_snssai(const ItemsElement & value) { this->snssai = value; }

        const ItemsElement & get_plmn_id() const { return plmn_id; }
        ItemsElement & get_mutable_plmn_id() { return plmn_id; }
        void set_plmn_id(const ItemsElement & value) { this->plmn_id = value; }

        const ItemsElement & get_the_5__qi_list() const { return the_5_qi_list; }
        ItemsElement & get_mutable_the_5__qi_list() { return the_5_qi_list; }
        void set_the_5__qi_list(const ItemsElement & value) { this->the_5_qi_list = value; }
    };

    class PartitionFlowListItems {
        public:
        PartitionFlowListItems() = default;
        virtual ~PartitionFlowListItems() = default;

        private:
        EutraCellIdentityType type;
        PurpleProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const PurpleProperties & get_properties() const { return properties; }
        PurpleProperties & get_mutable_properties() { return properties; }
        void set_properties(const PurpleProperties & value) { this->properties = value; }
    };

    class PartitionFlowList {
        public:
        PartitionFlowList() = default;
        virtual ~PartitionFlowList() = default;

        private:
        The5QiListType type;
        PartitionFlowListItems items;

        public:
        const The5QiListType & get_type() const { return type; }
        The5QiListType & get_mutable_type() { return type; }
        void set_type(const The5QiListType & value) { this->type = value; }

        const PartitionFlowListItems & get_items() const { return items; }
        PartitionFlowListItems & get_mutable_items() { return items; }
        void set_items(const PartitionFlowListItems & value) { this->items = value; }
    };

    class FluffyProperties {
        public:
        FluffyProperties() = default;
        virtual ~FluffyProperties() = default;

        private:
        EutraCellIdentity p_offset_to_point_a;
        EutraCellIdentity p_number_of_r_bs;
        ItemsElement partition_flow_list;

        public:
        const EutraCellIdentity & get_p_offset_to_point_a() const { return p_offset_to_point_a; }
        EutraCellIdentity & get_mutable_p_offset_to_point_a() { return p_offset_to_point_a; }
        void set_p_offset_to_point_a(const EutraCellIdentity & value) { this->p_offset_to_point_a = value; }

        const EutraCellIdentity & get_p_number_of_r_bs() const { return p_number_of_r_bs; }
        EutraCellIdentity & get_mutable_p_number_of_r_bs() { return p_number_of_r_bs; }
        void set_p_number_of_r_bs(const EutraCellIdentity & value) { this->p_number_of_r_bs = value; }

        const ItemsElement & get_partition_flow_list() const { return partition_flow_list; }
        ItemsElement & get_mutable_partition_flow_list() { return partition_flow_list; }
        void set_partition_flow_list(const ItemsElement & value) { this->partition_flow_list = value; }
    };

    class PartitionListItems {
        public:
        PartitionListItems() = default;
        virtual ~PartitionListItems() = default;

        private:
        EutraCellIdentityType type;
        FluffyProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const FluffyProperties & get_properties() const { return properties; }
        FluffyProperties & get_mutable_properties() { return properties; }
        void set_properties(const FluffyProperties & value) { this->properties = value; }
    };

    class PartitionList {
        public:
        PartitionList() = default;
        virtual ~PartitionList() = default;

        private:
        The5QiListType type;
        PartitionListItems items;

        public:
        const The5QiListType & get_type() const { return type; }
        The5QiListType & get_mutable_type() { return type; }
        void set_type(const The5QiListType & value) { this->type = value; }

        const PartitionListItems & get_items() const { return items; }
        PartitionListItems & get_mutable_items() { return items; }
        void set_items(const PartitionListItems & value) { this->items = value; }
    };

    class PerfObjectiveProperties {
        public:
        PerfObjectiveProperties() = default;
        virtual ~PerfObjectiveProperties() = default;

        private:
        ItemsElement plmn_info_list;
        GnbCuUpId five_qi_value;
        EutraCellIdentity max_ngbr_flow_br;
        GnbCuUpId flow_br_avg_window;
        GnbCuUpId max_pd;
        GnbCuUpId target_pd;

        public:
        const ItemsElement & get_plmn_info_list() const { return plmn_info_list; }
        ItemsElement & get_mutable_plmn_info_list() { return plmn_info_list; }
        void set_plmn_info_list(const ItemsElement & value) { this->plmn_info_list = value; }

        const GnbCuUpId & get_five_qi_value() const { return five_qi_value; }
        GnbCuUpId & get_mutable_five_qi_value() { return five_qi_value; }
        void set_five_qi_value(const GnbCuUpId & value) { this->five_qi_value = value; }

        const EutraCellIdentity & get_max_ngbr_flow_br() const { return max_ngbr_flow_br; }
        EutraCellIdentity & get_mutable_max_ngbr_flow_br() { return max_ngbr_flow_br; }
        void set_max_ngbr_flow_br(const EutraCellIdentity & value) { this->max_ngbr_flow_br = value; }

        const GnbCuUpId & get_flow_br_avg_window() const { return flow_br_avg_window; }
        GnbCuUpId & get_mutable_flow_br_avg_window() { return flow_br_avg_window; }
        void set_flow_br_avg_window(const GnbCuUpId & value) { this->flow_br_avg_window = value; }

        const GnbCuUpId & get_max_pd() const { return max_pd; }
        GnbCuUpId & get_mutable_max_pd() { return max_pd; }
        void set_max_pd(const GnbCuUpId & value) { this->max_pd = value; }

        const GnbCuUpId & get_target_pd() const { return target_pd; }
        GnbCuUpId & get_mutable_target_pd() { return target_pd; }
        void set_target_pd(const GnbCuUpId & value) { this->target_pd = value; }
    };

    class PerfObjective {
        public:
        PerfObjective() = default;
        virtual ~PerfObjective() = default;

        private:
        EutraCellIdentityType type;
        PerfObjectiveProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const PerfObjectiveProperties & get_properties() const { return properties; }
        PerfObjectiveProperties & get_mutable_properties() { return properties; }
        void set_properties(const PerfObjectiveProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class NumberOfRBs {
        public:
        NumberOfRBs() = default;
        virtual ~NumberOfRBs() = default;

        private:
        EutraCellIdentityType type;
        int64_t minimum;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const int64_t & get_minimum() const { return minimum; }
        int64_t & get_mutable_minimum() { return minimum; }
        void set_minimum(const int64_t & value) { this->minimum = value; }
    };

    class TentacledProperties {
        public:
        TentacledProperties() = default;
        virtual ~TentacledProperties() = default;

        private:
        NumberOfRBs start_rb;
        NumberOfRBs number_of_r_bs;
        GnbCuUpId symbol_mask;
        EutraCellIdentity slot_mask;

        public:
        const NumberOfRBs & get_start_rb() const { return start_rb; }
        NumberOfRBs & get_mutable_start_rb() { return start_rb; }
        void set_start_rb(const NumberOfRBs & value) { this->start_rb = value; }

        const NumberOfRBs & get_number_of_r_bs() const { return number_of_r_bs; }
        NumberOfRBs & get_mutable_number_of_r_bs() { return number_of_r_bs; }
        void set_number_of_r_bs(const NumberOfRBs & value) { this->number_of_r_bs = value; }

        const GnbCuUpId & get_symbol_mask() const { return symbol_mask; }
        GnbCuUpId & get_mutable_symbol_mask() { return symbol_mask; }
        void set_symbol_mask(const GnbCuUpId & value) { this->symbol_mask = value; }

        const EutraCellIdentity & get_slot_mask() const { return slot_mask; }
        EutraCellIdentity & get_mutable_slot_mask() { return slot_mask; }
        void set_slot_mask(const EutraCellIdentity & value) { this->slot_mask = value; }
    };

    class PrbBlankingConfigurationListItems {
        public:
        PrbBlankingConfigurationListItems() = default;
        virtual ~PrbBlankingConfigurationListItems() = default;

        private:
        EutraCellIdentityType type;
        TentacledProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const TentacledProperties & get_properties() const { return properties; }
        TentacledProperties & get_mutable_properties() { return properties; }
        void set_properties(const TentacledProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class PrbBlankingConfigurationList {
        public:
        PrbBlankingConfigurationList() = default;
        virtual ~PrbBlankingConfigurationList() = default;

        private:
        The5QiListType type;
        PrbBlankingConfigurationListItems items;

        public:
        const The5QiListType & get_type() const { return type; }
        The5QiListType & get_mutable_type() { return type; }
        void set_type(const The5QiListType & value) { this->type = value; }

        const PrbBlankingConfigurationListItems & get_items() const { return items; }
        PrbBlankingConfigurationListItems & get_mutable_items() { return items; }
        void set_items(const PrbBlankingConfigurationListItems & value) { this->items = value; }
    };

    class QueryServiceProperties {
        public:
        QueryServiceProperties() = default;
        virtual ~QueryServiceProperties() = default;

        private:
        ItemsElement list_of_supported_query_styles;

        public:
        const ItemsElement & get_list_of_supported_query_styles() const { return list_of_supported_query_styles; }
        ItemsElement & get_mutable_list_of_supported_query_styles() { return list_of_supported_query_styles; }
        void set_list_of_supported_query_styles(const ItemsElement & value) { this->list_of_supported_query_styles = value; }
    };

    class QueryService {
        public:
        QueryService() = default;
        virtual ~QueryService() = default;

        private:
        EutraCellIdentityType type;
        QueryServiceProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const QueryServiceProperties & get_properties() const { return properties; }
        QueryServiceProperties & get_mutable_properties() { return properties; }
        void set_properties(const QueryServiceProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class QueryStyleProperties {
        public:
        QueryStyleProperties() = default;
        virtual ~QueryStyleProperties() = default;

        private:
        EutraCellIdentity query_service_style_type;
        EutraCellIdentity query_service_style_name;
        EutraCellIdentity query_service_header_format_type;
        EutraCellIdentity query_service_definition_format_type;
        EutraCellIdentity query_service_outcome_format_type;

        public:
        const EutraCellIdentity & get_query_service_style_type() const { return query_service_style_type; }
        EutraCellIdentity & get_mutable_query_service_style_type() { return query_service_style_type; }
        void set_query_service_style_type(const EutraCellIdentity & value) { this->query_service_style_type = value; }

        const EutraCellIdentity & get_query_service_style_name() const { return query_service_style_name; }
        EutraCellIdentity & get_mutable_query_service_style_name() { return query_service_style_name; }
        void set_query_service_style_name(const EutraCellIdentity & value) { this->query_service_style_name = value; }

        const EutraCellIdentity & get_query_service_header_format_type() const { return query_service_header_format_type; }
        EutraCellIdentity & get_mutable_query_service_header_format_type() { return query_service_header_format_type; }
        void set_query_service_header_format_type(const EutraCellIdentity & value) { this->query_service_header_format_type = value; }

        const EutraCellIdentity & get_query_service_definition_format_type() const { return query_service_definition_format_type; }
        EutraCellIdentity & get_mutable_query_service_definition_format_type() { return query_service_definition_format_type; }
        void set_query_service_definition_format_type(const EutraCellIdentity & value) { this->query_service_definition_format_type = value; }

        const EutraCellIdentity & get_query_service_outcome_format_type() const { return query_service_outcome_format_type; }
        EutraCellIdentity & get_mutable_query_service_outcome_format_type() { return query_service_outcome_format_type; }
        void set_query_service_outcome_format_type(const EutraCellIdentity & value) { this->query_service_outcome_format_type = value; }
    };

    class QueryStyle {
        public:
        QueryStyle() = default;
        virtual ~QueryStyle() = default;

        private:
        EutraCellIdentityType type;
        QueryStyleProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const QueryStyleProperties & get_properties() const { return properties; }
        QueryStyleProperties & get_mutable_properties() { return properties; }
        void set_properties(const QueryStyleProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RPolarizationItemProperties {
        public:
        RPolarizationItemProperties() = default;
        virtual ~RPolarizationItemProperties() = default;

        private:
        GnbCuUpId r_polarization_index;
        AdministrativeState r_polarization_type;

        public:
        const GnbCuUpId & get_r_polarization_index() const { return r_polarization_index; }
        GnbCuUpId & get_mutable_r_polarization_index() { return r_polarization_index; }
        void set_r_polarization_index(const GnbCuUpId & value) { this->r_polarization_index = value; }

        const AdministrativeState & get_r_polarization_type() const { return r_polarization_type; }
        AdministrativeState & get_mutable_r_polarization_type() { return r_polarization_type; }
        void set_r_polarization_type(const AdministrativeState & value) { this->r_polarization_type = value; }
    };

    class RPolarizationItem {
        public:
        RPolarizationItem() = default;
        virtual ~RPolarizationItem() = default;

        private:
        EutraCellIdentityType type;
        RPolarizationItemProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RPolarizationItemProperties & get_properties() const { return properties; }
        RPolarizationItemProperties & get_mutable_properties() { return properties; }
        void set_properties(const RPolarizationItemProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RanConfigurationStructureProperties {
        public:
        RanConfigurationStructureProperties() = default;
        virtual ~RanConfigurationStructureProperties() = default;

        private:
        EutraCellIdentity ran_configuration_structure_name;
        ItemsElement list_of_supported_attributes;

        public:
        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const ItemsElement & get_list_of_supported_attributes() const { return list_of_supported_attributes; }
        ItemsElement & get_mutable_list_of_supported_attributes() { return list_of_supported_attributes; }
        void set_list_of_supported_attributes(const ItemsElement & value) { this->list_of_supported_attributes = value; }
    };

    class RanConfigurationStructure {
        public:
        RanConfigurationStructure() = default;
        virtual ~RanConfigurationStructure() = default;

        private:
        EutraCellIdentityType type;
        RanConfigurationStructureProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RanConfigurationStructureProperties & get_properties() const { return properties; }
        RanConfigurationStructureProperties & get_mutable_properties() { return properties; }
        void set_properties(const RanConfigurationStructureProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RanConfigurationStructureForAdfProperties {
        public:
        RanConfigurationStructureForAdfProperties() = default;
        virtual ~RanConfigurationStructureForAdfProperties() = default;

        private:
        ChangeType report_type;
        EutraCellIdentity ran_configuration_structure_name;
        GEnbIdList list_of_attributes;

        public:
        const ChangeType & get_report_type() const { return report_type; }
        ChangeType & get_mutable_report_type() { return report_type; }
        void set_report_type(const ChangeType & value) { this->report_type = value; }

        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const GEnbIdList & get_list_of_attributes() const { return list_of_attributes; }
        GEnbIdList & get_mutable_list_of_attributes() { return list_of_attributes; }
        void set_list_of_attributes(const GEnbIdList & value) { this->list_of_attributes = value; }
    };

    class RanConfigurationStructureForAdf {
        public:
        RanConfigurationStructureForAdf() = default;
        virtual ~RanConfigurationStructureForAdf() = default;

        private:
        EutraCellIdentityType type;
        RanConfigurationStructureForAdfProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RanConfigurationStructureForAdfProperties & get_properties() const { return properties; }
        RanConfigurationStructureForAdfProperties & get_mutable_properties() { return properties; }
        void set_properties(const RanConfigurationStructureForAdfProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class The5_QiList {
        public:
        The5_QiList() = default;
        virtual ~The5_QiList() = default;

        private:
        The5QiListType type;
        EutraCellIdentity items;

        public:
        const The5QiListType & get_type() const { return type; }
        The5QiListType & get_mutable_type() { return type; }
        void set_type(const The5QiListType & value) { this->type = value; }

        const EutraCellIdentity & get_items() const { return items; }
        EutraCellIdentity & get_mutable_items() { return items; }
        void set_items(const EutraCellIdentity & value) { this->items = value; }
    };

    class RanConfigurationStructureForEventTriggerProperties {
        public:
        RanConfigurationStructureForEventTriggerProperties() = default;
        virtual ~RanConfigurationStructureForEventTriggerProperties() = default;

        private:
        EutraCellIdentity ran_configuration_structure_name;
        The5_QiList list_of_attributes;

        public:
        const EutraCellIdentity & get_ran_configuration_structure_name() const { return ran_configuration_structure_name; }
        EutraCellIdentity & get_mutable_ran_configuration_structure_name() { return ran_configuration_structure_name; }
        void set_ran_configuration_structure_name(const EutraCellIdentity & value) { this->ran_configuration_structure_name = value; }

        const The5_QiList & get_list_of_attributes() const { return list_of_attributes; }
        The5_QiList & get_mutable_list_of_attributes() { return list_of_attributes; }
        void set_list_of_attributes(const The5_QiList & value) { this->list_of_attributes = value; }
    };

    class RanConfigurationStructureForEventTrigger {
        public:
        RanConfigurationStructureForEventTrigger() = default;
        virtual ~RanConfigurationStructureForEventTrigger() = default;

        private:
        EutraCellIdentityType type;
        RanConfigurationStructureForEventTriggerProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RanConfigurationStructureForEventTriggerProperties & get_properties() const { return properties; }
        RanConfigurationStructureForEventTriggerProperties & get_mutable_properties() { return properties; }
        void set_properties(const RanConfigurationStructureForEventTriggerProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RanFunctionDefinitionProperties {
        public:
        RanFunctionDefinitionProperties() = default;
        virtual ~RanFunctionDefinitionProperties() = default;

        private:
        ItemsElement ran_function_name;
        ItemsElement list_of_supported_node_level_configuration_structures;
        ItemsElement list_of_cells_for_ran_function_definition;

        public:
        const ItemsElement & get_ran_function_name() const { return ran_function_name; }
        ItemsElement & get_mutable_ran_function_name() { return ran_function_name; }
        void set_ran_function_name(const ItemsElement & value) { this->ran_function_name = value; }

        const ItemsElement & get_list_of_supported_node_level_configuration_structures() const { return list_of_supported_node_level_configuration_structures; }
        ItemsElement & get_mutable_list_of_supported_node_level_configuration_structures() { return list_of_supported_node_level_configuration_structures; }
        void set_list_of_supported_node_level_configuration_structures(const ItemsElement & value) { this->list_of_supported_node_level_configuration_structures = value; }

        const ItemsElement & get_list_of_cells_for_ran_function_definition() const { return list_of_cells_for_ran_function_definition; }
        ItemsElement & get_mutable_list_of_cells_for_ran_function_definition() { return list_of_cells_for_ran_function_definition; }
        void set_list_of_cells_for_ran_function_definition(const ItemsElement & value) { this->list_of_cells_for_ran_function_definition = value; }
    };

    class RanFunctionDefinition {
        public:
        RanFunctionDefinition() = default;
        virtual ~RanFunctionDefinition() = default;

        private:
        EutraCellIdentityType type;
        RanFunctionDefinitionProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RanFunctionDefinitionProperties & get_properties() const { return properties; }
        RanFunctionDefinitionProperties & get_mutable_properties() { return properties; }
        void set_properties(const RanFunctionDefinitionProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RanFunctionNameProperties {
        public:
        RanFunctionNameProperties() = default;
        virtual ~RanFunctionNameProperties() = default;

        private:
        EutraCellIdentity ran_function_short_name;
        EutraCellIdentity ran_function_service_model_oid;
        EutraCellIdentity ran_function_description;
        EutraCellIdentity ran_function_instance;

        public:
        const EutraCellIdentity & get_ran_function_short_name() const { return ran_function_short_name; }
        EutraCellIdentity & get_mutable_ran_function_short_name() { return ran_function_short_name; }
        void set_ran_function_short_name(const EutraCellIdentity & value) { this->ran_function_short_name = value; }

        const EutraCellIdentity & get_ran_function_service_model_oid() const { return ran_function_service_model_oid; }
        EutraCellIdentity & get_mutable_ran_function_service_model_oid() { return ran_function_service_model_oid; }
        void set_ran_function_service_model_oid(const EutraCellIdentity & value) { this->ran_function_service_model_oid = value; }

        const EutraCellIdentity & get_ran_function_description() const { return ran_function_description; }
        EutraCellIdentity & get_mutable_ran_function_description() { return ran_function_description; }
        void set_ran_function_description(const EutraCellIdentity & value) { this->ran_function_description = value; }

        const EutraCellIdentity & get_ran_function_instance() const { return ran_function_instance; }
        EutraCellIdentity & get_mutable_ran_function_instance() { return ran_function_instance; }
        void set_ran_function_instance(const EutraCellIdentity & value) { this->ran_function_instance = value; }
    };

    class RanFunctionName {
        public:
        RanFunctionName() = default;
        virtual ~RanFunctionName() = default;

        private:
        EutraCellIdentityType type;
        RanFunctionNameProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RanFunctionNameProperties & get_properties() const { return properties; }
        RanFunctionNameProperties & get_mutable_properties() { return properties; }
        void set_properties(const RanFunctionNameProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ReportServiceProperties {
        public:
        ReportServiceProperties() = default;
        virtual ~ReportServiceProperties() = default;

        private:
        ItemsElement list_of_supported_report_styles;

        public:
        const ItemsElement & get_list_of_supported_report_styles() const { return list_of_supported_report_styles; }
        ItemsElement & get_mutable_list_of_supported_report_styles() { return list_of_supported_report_styles; }
        void set_list_of_supported_report_styles(const ItemsElement & value) { this->list_of_supported_report_styles = value; }
    };

    class ReportService {
        public:
        ReportService() = default;
        virtual ~ReportService() = default;

        private:
        EutraCellIdentityType type;
        ReportServiceProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ReportServiceProperties & get_properties() const { return properties; }
        ReportServiceProperties & get_mutable_properties() { return properties; }
        void set_properties(const ReportServiceProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ReportStyleProperties {
        public:
        ReportStyleProperties() = default;
        virtual ~ReportStyleProperties() = default;

        private:
        EutraCellIdentity report_service_style_type;
        EutraCellIdentity report_service_style_name;
        GEnbIdList list_of_supported_event_trigger_styles_for_report_style;
        EutraCellIdentity report_service_action_definition_format_type;
        EutraCellIdentity report_service_indication_header_format_type;
        EutraCellIdentity report_service_indication_message_format_type;

        public:
        const EutraCellIdentity & get_report_service_style_type() const { return report_service_style_type; }
        EutraCellIdentity & get_mutable_report_service_style_type() { return report_service_style_type; }
        void set_report_service_style_type(const EutraCellIdentity & value) { this->report_service_style_type = value; }

        const EutraCellIdentity & get_report_service_style_name() const { return report_service_style_name; }
        EutraCellIdentity & get_mutable_report_service_style_name() { return report_service_style_name; }
        void set_report_service_style_name(const EutraCellIdentity & value) { this->report_service_style_name = value; }

        const GEnbIdList & get_list_of_supported_event_trigger_styles_for_report_style() const { return list_of_supported_event_trigger_styles_for_report_style; }
        GEnbIdList & get_mutable_list_of_supported_event_trigger_styles_for_report_style() { return list_of_supported_event_trigger_styles_for_report_style; }
        void set_list_of_supported_event_trigger_styles_for_report_style(const GEnbIdList & value) { this->list_of_supported_event_trigger_styles_for_report_style = value; }

        const EutraCellIdentity & get_report_service_action_definition_format_type() const { return report_service_action_definition_format_type; }
        EutraCellIdentity & get_mutable_report_service_action_definition_format_type() { return report_service_action_definition_format_type; }
        void set_report_service_action_definition_format_type(const EutraCellIdentity & value) { this->report_service_action_definition_format_type = value; }

        const EutraCellIdentity & get_report_service_indication_header_format_type() const { return report_service_indication_header_format_type; }
        EutraCellIdentity & get_mutable_report_service_indication_header_format_type() { return report_service_indication_header_format_type; }
        void set_report_service_indication_header_format_type(const EutraCellIdentity & value) { this->report_service_indication_header_format_type = value; }

        const EutraCellIdentity & get_report_service_indication_message_format_type() const { return report_service_indication_message_format_type; }
        EutraCellIdentity & get_mutable_report_service_indication_message_format_type() { return report_service_indication_message_format_type; }
        void set_report_service_indication_message_format_type(const EutraCellIdentity & value) { this->report_service_indication_message_format_type = value; }
    };

    class ReportStyle {
        public:
        ReportStyle() = default;
        virtual ~ReportStyle() = default;

        private:
        EutraCellIdentityType type;
        ReportStyleProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ReportStyleProperties & get_properties() const { return properties; }
        ReportStyleProperties & get_mutable_properties() { return properties; }
        void set_properties(const ReportStyleProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicActionDefinitionProperties {
        public:
        RicActionDefinitionProperties() = default;
        virtual ~RicActionDefinitionProperties() = default;

        private:
        EutraCellIdentity ric_style_type;
        ItemsElement action_definition_format;

        public:
        const EutraCellIdentity & get_ric_style_type() const { return ric_style_type; }
        EutraCellIdentity & get_mutable_ric_style_type() { return ric_style_type; }
        void set_ric_style_type(const EutraCellIdentity & value) { this->ric_style_type = value; }

        const ItemsElement & get_action_definition_format() const { return action_definition_format; }
        ItemsElement & get_mutable_action_definition_format() { return action_definition_format; }
        void set_action_definition_format(const ItemsElement & value) { this->action_definition_format = value; }
    };

    class RicActionDefinition {
        public:
        RicActionDefinition() = default;
        virtual ~RicActionDefinition() = default;

        private:
        EutraCellIdentityType type;
        RicActionDefinitionProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicActionDefinitionProperties & get_properties() const { return properties; }
        RicActionDefinitionProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicActionDefinitionProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicControlHeaderProperties {
        public:
        RicControlHeaderProperties() = default;
        virtual ~RicControlHeaderProperties() = default;

        private:
        ItemsElement control_header_format;

        public:
        const ItemsElement & get_control_header_format() const { return control_header_format; }
        ItemsElement & get_mutable_control_header_format() { return control_header_format; }
        void set_control_header_format(const ItemsElement & value) { this->control_header_format = value; }
    };

    class RicControlHeader {
        public:
        RicControlHeader() = default;
        virtual ~RicControlHeader() = default;

        private:
        EutraCellIdentityType type;
        RicControlHeaderProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicControlHeaderProperties & get_properties() const { return properties; }
        RicControlHeaderProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicControlHeaderProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicControlMessageProperties {
        public:
        RicControlMessageProperties() = default;
        virtual ~RicControlMessageProperties() = default;

        private:
        ItemsElement control_message_format;

        public:
        const ItemsElement & get_control_message_format() const { return control_message_format; }
        ItemsElement & get_mutable_control_message_format() { return control_message_format; }
        void set_control_message_format(const ItemsElement & value) { this->control_message_format = value; }
    };

    class RicControlMessage {
        public:
        RicControlMessage() = default;
        virtual ~RicControlMessage() = default;

        private:
        EutraCellIdentityType type;
        RicControlMessageProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicControlMessageProperties & get_properties() const { return properties; }
        RicControlMessageProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicControlMessageProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicControlOutcomeProperties {
        public:
        RicControlOutcomeProperties() = default;
        virtual ~RicControlOutcomeProperties() = default;

        private:
        ItemsElement control_outcome_format;

        public:
        const ItemsElement & get_control_outcome_format() const { return control_outcome_format; }
        ItemsElement & get_mutable_control_outcome_format() { return control_outcome_format; }
        void set_control_outcome_format(const ItemsElement & value) { this->control_outcome_format = value; }
    };

    class RicControlOutcome {
        public:
        RicControlOutcome() = default;
        virtual ~RicControlOutcome() = default;

        private:
        EutraCellIdentityType type;
        RicControlOutcomeProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicControlOutcomeProperties & get_properties() const { return properties; }
        RicControlOutcomeProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicControlOutcomeProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicEventTriggerDefinitionProperties {
        public:
        RicEventTriggerDefinitionProperties() = default;
        virtual ~RicEventTriggerDefinitionProperties() = default;

        private:
        ItemsElement event_trigger_definition_format;

        public:
        const ItemsElement & get_event_trigger_definition_format() const { return event_trigger_definition_format; }
        ItemsElement & get_mutable_event_trigger_definition_format() { return event_trigger_definition_format; }
        void set_event_trigger_definition_format(const ItemsElement & value) { this->event_trigger_definition_format = value; }
    };

    class RicEventTriggerDefinition {
        public:
        RicEventTriggerDefinition() = default;
        virtual ~RicEventTriggerDefinition() = default;

        private:
        EutraCellIdentityType type;
        RicEventTriggerDefinitionProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicEventTriggerDefinitionProperties & get_properties() const { return properties; }
        RicEventTriggerDefinitionProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicEventTriggerDefinitionProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicIndicationHeaderProperties {
        public:
        RicIndicationHeaderProperties() = default;
        virtual ~RicIndicationHeaderProperties() = default;

        private:
        ItemsElement indication_header_format;

        public:
        const ItemsElement & get_indication_header_format() const { return indication_header_format; }
        ItemsElement & get_mutable_indication_header_format() { return indication_header_format; }
        void set_indication_header_format(const ItemsElement & value) { this->indication_header_format = value; }
    };

    class RicIndicationHeader {
        public:
        RicIndicationHeader() = default;
        virtual ~RicIndicationHeader() = default;

        private:
        EutraCellIdentityType type;
        RicIndicationHeaderProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicIndicationHeaderProperties & get_properties() const { return properties; }
        RicIndicationHeaderProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicIndicationHeaderProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicIndicationMessageProperties {
        public:
        RicIndicationMessageProperties() = default;
        virtual ~RicIndicationMessageProperties() = default;

        private:
        ItemsElement indication_message_format;

        public:
        const ItemsElement & get_indication_message_format() const { return indication_message_format; }
        ItemsElement & get_mutable_indication_message_format() { return indication_message_format; }
        void set_indication_message_format(const ItemsElement & value) { this->indication_message_format = value; }
    };

    class RicIndicationMessage {
        public:
        RicIndicationMessage() = default;
        virtual ~RicIndicationMessage() = default;

        private:
        EutraCellIdentityType type;
        RicIndicationMessageProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicIndicationMessageProperties & get_properties() const { return properties; }
        RicIndicationMessageProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicIndicationMessageProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicQueryDefinitionProperties {
        public:
        RicQueryDefinitionProperties() = default;
        virtual ~RicQueryDefinitionProperties() = default;

        private:
        ItemsElement query_definition_format;

        public:
        const ItemsElement & get_query_definition_format() const { return query_definition_format; }
        ItemsElement & get_mutable_query_definition_format() { return query_definition_format; }
        void set_query_definition_format(const ItemsElement & value) { this->query_definition_format = value; }
    };

    class RicQueryDefinition {
        public:
        RicQueryDefinition() = default;
        virtual ~RicQueryDefinition() = default;

        private:
        EutraCellIdentityType type;
        RicQueryDefinitionProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicQueryDefinitionProperties & get_properties() const { return properties; }
        RicQueryDefinitionProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicQueryDefinitionProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicQueryHeaderProperties {
        public:
        RicQueryHeaderProperties() = default;
        virtual ~RicQueryHeaderProperties() = default;

        private:
        ItemsElement query_header_format;

        public:
        const ItemsElement & get_query_header_format() const { return query_header_format; }
        ItemsElement & get_mutable_query_header_format() { return query_header_format; }
        void set_query_header_format(const ItemsElement & value) { this->query_header_format = value; }
    };

    class RicQueryHeader {
        public:
        RicQueryHeader() = default;
        virtual ~RicQueryHeader() = default;

        private:
        EutraCellIdentityType type;
        RicQueryHeaderProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicQueryHeaderProperties & get_properties() const { return properties; }
        RicQueryHeaderProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicQueryHeaderProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicQueryOutcomeProperties {
        public:
        RicQueryOutcomeProperties() = default;
        virtual ~RicQueryOutcomeProperties() = default;

        private:
        ItemsElement query_outcome_format;

        public:
        const ItemsElement & get_query_outcome_format() const { return query_outcome_format; }
        ItemsElement & get_mutable_query_outcome_format() { return query_outcome_format; }
        void set_query_outcome_format(const ItemsElement & value) { this->query_outcome_format = value; }
    };

    class RicQueryOutcome {
        public:
        RicQueryOutcome() = default;
        virtual ~RicQueryOutcome() = default;

        private:
        EutraCellIdentityType type;
        RicQueryOutcomeProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicQueryOutcomeProperties & get_properties() const { return properties; }
        RicQueryOutcomeProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicQueryOutcomeProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class RicServicesProperties {
        public:
        RicServicesProperties() = default;
        virtual ~RicServicesProperties() = default;

        private:
        ItemsElement event_trigger;
        ItemsElement report_service;
        ItemsElement insert_service;
        ItemsElement control_service;
        ItemsElement policy_service;
        ItemsElement query_service;

        public:
        const ItemsElement & get_event_trigger() const { return event_trigger; }
        ItemsElement & get_mutable_event_trigger() { return event_trigger; }
        void set_event_trigger(const ItemsElement & value) { this->event_trigger = value; }

        const ItemsElement & get_report_service() const { return report_service; }
        ItemsElement & get_mutable_report_service() { return report_service; }
        void set_report_service(const ItemsElement & value) { this->report_service = value; }

        const ItemsElement & get_insert_service() const { return insert_service; }
        ItemsElement & get_mutable_insert_service() { return insert_service; }
        void set_insert_service(const ItemsElement & value) { this->insert_service = value; }

        const ItemsElement & get_control_service() const { return control_service; }
        ItemsElement & get_mutable_control_service() { return control_service; }
        void set_control_service(const ItemsElement & value) { this->control_service = value; }

        const ItemsElement & get_policy_service() const { return policy_service; }
        ItemsElement & get_mutable_policy_service() { return policy_service; }
        void set_policy_service(const ItemsElement & value) { this->policy_service = value; }

        const ItemsElement & get_query_service() const { return query_service; }
        ItemsElement & get_mutable_query_service() { return query_service; }
        void set_query_service(const ItemsElement & value) { this->query_service = value; }
    };

    class RicServices {
        public:
        RicServices() = default;
        virtual ~RicServices() = default;

        private:
        EutraCellIdentityType type;
        RicServicesProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RicServicesProperties & get_properties() const { return properties; }
        RicServicesProperties & get_mutable_properties() { return properties; }
        void set_properties(const RicServicesProperties & value) { this->properties = value; }
    };

    class RGainCorrectionRangeProperties {
        public:
        RGainCorrectionRangeProperties() = default;
        virtual ~RGainCorrectionRangeProperties() = default;

        private:
        EutraCellIdentity r_max;
        EutraCellIdentity r_min;

        public:
        const EutraCellIdentity & get_r_max() const { return r_max; }
        EutraCellIdentity & get_mutable_r_max() { return r_max; }
        void set_r_max(const EutraCellIdentity & value) { this->r_max = value; }

        const EutraCellIdentity & get_r_min() const { return r_min; }
        EutraCellIdentity & get_mutable_r_min() { return r_min; }
        void set_r_min(const EutraCellIdentity & value) { this->r_min = value; }
    };

    class RGainCorrectionRange {
        public:
        RGainCorrectionRange() = default;
        virtual ~RGainCorrectionRange() = default;

        private:
        EutraCellIdentityType type;
        RGainCorrectionRangeProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RGainCorrectionRangeProperties & get_properties() const { return properties; }
        RGainCorrectionRangeProperties & get_mutable_properties() { return properties; }
        void set_properties(const RGainCorrectionRangeProperties & value) { this->properties = value; }
    };

    class RLeftmostBottomArrayElementPositionProperties {
        public:
        RLeftmostBottomArrayElementPositionProperties() = default;
        virtual ~RLeftmostBottomArrayElementPositionProperties() = default;

        private:
        EutraCellIdentity r_x_axis;
        EutraCellIdentity r_y_axis;
        EutraCellIdentity r_z_axis;

        public:
        const EutraCellIdentity & get_r_x_axis() const { return r_x_axis; }
        EutraCellIdentity & get_mutable_r_x_axis() { return r_x_axis; }
        void set_r_x_axis(const EutraCellIdentity & value) { this->r_x_axis = value; }

        const EutraCellIdentity & get_r_y_axis() const { return r_y_axis; }
        EutraCellIdentity & get_mutable_r_y_axis() { return r_y_axis; }
        void set_r_y_axis(const EutraCellIdentity & value) { this->r_y_axis = value; }

        const EutraCellIdentity & get_r_z_axis() const { return r_z_axis; }
        EutraCellIdentity & get_mutable_r_z_axis() { return r_z_axis; }
        void set_r_z_axis(const EutraCellIdentity & value) { this->r_z_axis = value; }
    };

    class RLeftmostBottomArrayElementPosition {
        public:
        RLeftmostBottomArrayElementPosition() = default;
        virtual ~RLeftmostBottomArrayElementPosition() = default;

        private:
        EutraCellIdentityType type;
        RLeftmostBottomArrayElementPositionProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RLeftmostBottomArrayElementPositionProperties & get_properties() const { return properties; }
        RLeftmostBottomArrayElementPositionProperties & get_mutable_properties() { return properties; }
        void set_properties(const RLeftmostBottomArrayElementPositionProperties & value) { this->properties = value; }
    };

    class RNormalVectorDirectionProperties {
        public:
        RNormalVectorDirectionProperties() = default;
        virtual ~RNormalVectorDirectionProperties() = default;

        private:
        EutraCellIdentity r_azimuth_angle;
        EutraCellIdentity r_zenith_angle;

        public:
        const EutraCellIdentity & get_r_azimuth_angle() const { return r_azimuth_angle; }
        EutraCellIdentity & get_mutable_r_azimuth_angle() { return r_azimuth_angle; }
        void set_r_azimuth_angle(const EutraCellIdentity & value) { this->r_azimuth_angle = value; }

        const EutraCellIdentity & get_r_zenith_angle() const { return r_zenith_angle; }
        EutraCellIdentity & get_mutable_r_zenith_angle() { return r_zenith_angle; }
        void set_r_zenith_angle(const EutraCellIdentity & value) { this->r_zenith_angle = value; }
    };

    class RNormalVectorDirection {
        public:
        RNormalVectorDirection() = default;
        virtual ~RNormalVectorDirection() = default;

        private:
        EutraCellIdentityType type;
        RNormalVectorDirectionProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RNormalVectorDirectionProperties & get_properties() const { return properties; }
        RNormalVectorDirectionProperties & get_mutable_properties() { return properties; }
        void set_properties(const RNormalVectorDirectionProperties & value) { this->properties = value; }
    };

    class RxArrayItemProperties {
        public:
        RxArrayItemProperties() = default;
        virtual ~RxArrayItemProperties() = default;

        private:
        EutraCellIdentity r_name;
        GnbCuUpId r_number_of_rows;
        GnbCuUpId r_number_of_columns;
        GnbCuUpId r_number_of_array_layers;
        EutraCellIdentity r_horizontal_spacing;
        EutraCellIdentity r_vertical_spacing;
        RNormalVectorDirection r_normal_vector_direction;
        RLeftmostBottomArrayElementPosition r_leftmost_bottom_array_element_position;
        GEnbIdList r_polarization_list;
        GnbCuUpId r_band_number;
        RGainCorrectionRange r_gain_correction_range;

        public:
        const EutraCellIdentity & get_r_name() const { return r_name; }
        EutraCellIdentity & get_mutable_r_name() { return r_name; }
        void set_r_name(const EutraCellIdentity & value) { this->r_name = value; }

        const GnbCuUpId & get_r_number_of_rows() const { return r_number_of_rows; }
        GnbCuUpId & get_mutable_r_number_of_rows() { return r_number_of_rows; }
        void set_r_number_of_rows(const GnbCuUpId & value) { this->r_number_of_rows = value; }

        const GnbCuUpId & get_r_number_of_columns() const { return r_number_of_columns; }
        GnbCuUpId & get_mutable_r_number_of_columns() { return r_number_of_columns; }
        void set_r_number_of_columns(const GnbCuUpId & value) { this->r_number_of_columns = value; }

        const GnbCuUpId & get_r_number_of_array_layers() const { return r_number_of_array_layers; }
        GnbCuUpId & get_mutable_r_number_of_array_layers() { return r_number_of_array_layers; }
        void set_r_number_of_array_layers(const GnbCuUpId & value) { this->r_number_of_array_layers = value; }

        const EutraCellIdentity & get_r_horizontal_spacing() const { return r_horizontal_spacing; }
        EutraCellIdentity & get_mutable_r_horizontal_spacing() { return r_horizontal_spacing; }
        void set_r_horizontal_spacing(const EutraCellIdentity & value) { this->r_horizontal_spacing = value; }

        const EutraCellIdentity & get_r_vertical_spacing() const { return r_vertical_spacing; }
        EutraCellIdentity & get_mutable_r_vertical_spacing() { return r_vertical_spacing; }
        void set_r_vertical_spacing(const EutraCellIdentity & value) { this->r_vertical_spacing = value; }

        const RNormalVectorDirection & get_r_normal_vector_direction() const { return r_normal_vector_direction; }
        RNormalVectorDirection & get_mutable_r_normal_vector_direction() { return r_normal_vector_direction; }
        void set_r_normal_vector_direction(const RNormalVectorDirection & value) { this->r_normal_vector_direction = value; }

        const RLeftmostBottomArrayElementPosition & get_r_leftmost_bottom_array_element_position() const { return r_leftmost_bottom_array_element_position; }
        RLeftmostBottomArrayElementPosition & get_mutable_r_leftmost_bottom_array_element_position() { return r_leftmost_bottom_array_element_position; }
        void set_r_leftmost_bottom_array_element_position(const RLeftmostBottomArrayElementPosition & value) { this->r_leftmost_bottom_array_element_position = value; }

        const GEnbIdList & get_r_polarization_list() const { return r_polarization_list; }
        GEnbIdList & get_mutable_r_polarization_list() { return r_polarization_list; }
        void set_r_polarization_list(const GEnbIdList & value) { this->r_polarization_list = value; }

        const GnbCuUpId & get_r_band_number() const { return r_band_number; }
        GnbCuUpId & get_mutable_r_band_number() { return r_band_number; }
        void set_r_band_number(const GnbCuUpId & value) { this->r_band_number = value; }

        const RGainCorrectionRange & get_r_gain_correction_range() const { return r_gain_correction_range; }
        RGainCorrectionRange & get_mutable_r_gain_correction_range() { return r_gain_correction_range; }
        void set_r_gain_correction_range(const RGainCorrectionRange & value) { this->r_gain_correction_range = value; }
    };

    class RxArrayItem {
        public:
        RxArrayItem() = default;
        virtual ~RxArrayItem() = default;

        private:
        EutraCellIdentityType type;
        RxArrayItemProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const RxArrayItemProperties & get_properties() const { return properties; }
        RxArrayItemProperties & get_mutable_properties() { return properties; }
        void set_properties(const RxArrayItemProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class SleepModeProperties {
        public:
        SleepModeProperties() = default;
        virtual ~SleepModeProperties() = default;

        private:
        AdministrativeState sleep_mode_type;
        EutraCellIdentity wakeup_duration;
        EutraCellIdentity wakeup_duration_guaranteed;

        public:
        const AdministrativeState & get_sleep_mode_type() const { return sleep_mode_type; }
        AdministrativeState & get_mutable_sleep_mode_type() { return sleep_mode_type; }
        void set_sleep_mode_type(const AdministrativeState & value) { this->sleep_mode_type = value; }

        const EutraCellIdentity & get_wakeup_duration() const { return wakeup_duration; }
        EutraCellIdentity & get_mutable_wakeup_duration() { return wakeup_duration; }
        void set_wakeup_duration(const EutraCellIdentity & value) { this->wakeup_duration = value; }

        const EutraCellIdentity & get_wakeup_duration_guaranteed() const { return wakeup_duration_guaranteed; }
        EutraCellIdentity & get_mutable_wakeup_duration_guaranteed() { return wakeup_duration_guaranteed; }
        void set_wakeup_duration_guaranteed(const EutraCellIdentity & value) { this->wakeup_duration_guaranteed = value; }
    };

    class SleepMode {
        public:
        SleepMode() = default;
        virtual ~SleepMode() = default;

        private:
        EutraCellIdentityType type;
        SleepModeProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const SleepModeProperties & get_properties() const { return properties; }
        SleepModeProperties & get_mutable_properties() { return properties; }
        void set_properties(const SleepModeProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class SnssaiProperties {
        public:
        SnssaiProperties() = default;
        virtual ~SnssaiProperties() = default;

        private:
        ItemsElement sst;
        EutraCellIdentity sd;

        public:
        const ItemsElement & get_sst() const { return sst; }
        ItemsElement & get_mutable_sst() { return sst; }
        void set_sst(const ItemsElement & value) { this->sst = value; }

        const EutraCellIdentity & get_sd() const { return sd; }
        EutraCellIdentity & get_mutable_sd() { return sd; }
        void set_sd(const EutraCellIdentity & value) { this->sd = value; }
    };

    class Snssai {
        public:
        Snssai() = default;
        virtual ~Snssai() = default;

        private:
        EutraCellIdentityType type;
        SnssaiProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const SnssaiProperties & get_properties() const { return properties; }
        SnssaiProperties & get_mutable_properties() { return properties; }
        void set_properties(const SnssaiProperties & value) { this->properties = value; }
    };

    class SsbDuration {
        public:
        SsbDuration() = default;
        virtual ~SsbDuration() = default;

        private:
        EutraCellIdentityType type;
        std::vector<int64_t> ssb_duration_enum;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const std::vector<int64_t> & get_ssb_duration_enum() const { return ssb_duration_enum; }
        std::vector<int64_t> & get_mutable_ssb_duration_enum() { return ssb_duration_enum; }
        void set_ssb_duration_enum(const std::vector<int64_t> & value) { this->ssb_duration_enum = value; }
    };

    class Sst {
        public:
        Sst() = default;
        virtual ~Sst() = default;

        private:
        EutraCellIdentityType type;
        int64_t maximum;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const int64_t & get_maximum() const { return maximum; }
        int64_t & get_mutable_maximum() { return maximum; }
        void set_maximum(const int64_t & value) { this->maximum = value; }
    };

    class SupportedTrxControlMaskProperties {
        public:
        SupportedTrxControlMaskProperties() = default;
        virtual ~SupportedTrxControlMaskProperties() = default;

        private:
        EutraCellIdentity mask_name;
        EutraCellIdentity antenna_mask;

        public:
        const EutraCellIdentity & get_mask_name() const { return mask_name; }
        EutraCellIdentity & get_mutable_mask_name() { return mask_name; }
        void set_mask_name(const EutraCellIdentity & value) { this->mask_name = value; }

        const EutraCellIdentity & get_antenna_mask() const { return antenna_mask; }
        EutraCellIdentity & get_mutable_antenna_mask() { return antenna_mask; }
        void set_antenna_mask(const EutraCellIdentity & value) { this->antenna_mask = value; }
    };

    class SupportedTrxControlMask {
        public:
        SupportedTrxControlMask() = default;
        virtual ~SupportedTrxControlMask() = default;

        private:
        EutraCellIdentityType type;
        SupportedTrxControlMaskProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const SupportedTrxControlMaskProperties & get_properties() const { return properties; }
        SupportedTrxControlMaskProperties & get_mutable_properties() { return properties; }
        void set_properties(const SupportedTrxControlMaskProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class TPolarizationItemProperties {
        public:
        TPolarizationItemProperties() = default;
        virtual ~TPolarizationItemProperties() = default;

        private:
        GnbCuUpId t_polarization_index;
        AdministrativeState t_polarization_type;

        public:
        const GnbCuUpId & get_t_polarization_index() const { return t_polarization_index; }
        GnbCuUpId & get_mutable_t_polarization_index() { return t_polarization_index; }
        void set_t_polarization_index(const GnbCuUpId & value) { this->t_polarization_index = value; }

        const AdministrativeState & get_t_polarization_type() const { return t_polarization_type; }
        AdministrativeState & get_mutable_t_polarization_type() { return t_polarization_type; }
        void set_t_polarization_type(const AdministrativeState & value) { this->t_polarization_type = value; }
    };

    class TPolarizationItem {
        public:
        TPolarizationItem() = default;
        virtual ~TPolarizationItem() = default;

        private:
        EutraCellIdentityType type;
        TPolarizationItemProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const TPolarizationItemProperties & get_properties() const { return properties; }
        TPolarizationItemProperties & get_mutable_properties() { return properties; }
        void set_properties(const TPolarizationItemProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class TLeftmostBottomArrayElementPositionProperties {
        public:
        TLeftmostBottomArrayElementPositionProperties() = default;
        virtual ~TLeftmostBottomArrayElementPositionProperties() = default;

        private:
        EutraCellIdentity t_x_axis;
        EutraCellIdentity t_y_axis;
        EutraCellIdentity t_z_axis;

        public:
        const EutraCellIdentity & get_t_x_axis() const { return t_x_axis; }
        EutraCellIdentity & get_mutable_t_x_axis() { return t_x_axis; }
        void set_t_x_axis(const EutraCellIdentity & value) { this->t_x_axis = value; }

        const EutraCellIdentity & get_t_y_axis() const { return t_y_axis; }
        EutraCellIdentity & get_mutable_t_y_axis() { return t_y_axis; }
        void set_t_y_axis(const EutraCellIdentity & value) { this->t_y_axis = value; }

        const EutraCellIdentity & get_t_z_axis() const { return t_z_axis; }
        EutraCellIdentity & get_mutable_t_z_axis() { return t_z_axis; }
        void set_t_z_axis(const EutraCellIdentity & value) { this->t_z_axis = value; }
    };

    class TLeftmostBottomArrayElementPosition {
        public:
        TLeftmostBottomArrayElementPosition() = default;
        virtual ~TLeftmostBottomArrayElementPosition() = default;

        private:
        EutraCellIdentityType type;
        TLeftmostBottomArrayElementPositionProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const TLeftmostBottomArrayElementPositionProperties & get_properties() const { return properties; }
        TLeftmostBottomArrayElementPositionProperties & get_mutable_properties() { return properties; }
        void set_properties(const TLeftmostBottomArrayElementPositionProperties & value) { this->properties = value; }
    };

    class TNormalVectorDirectionProperties {
        public:
        TNormalVectorDirectionProperties() = default;
        virtual ~TNormalVectorDirectionProperties() = default;

        private:
        EutraCellIdentity t_azimuth_angle;
        EutraCellIdentity t_zenith_angle;

        public:
        const EutraCellIdentity & get_t_azimuth_angle() const { return t_azimuth_angle; }
        EutraCellIdentity & get_mutable_t_azimuth_angle() { return t_azimuth_angle; }
        void set_t_azimuth_angle(const EutraCellIdentity & value) { this->t_azimuth_angle = value; }

        const EutraCellIdentity & get_t_zenith_angle() const { return t_zenith_angle; }
        EutraCellIdentity & get_mutable_t_zenith_angle() { return t_zenith_angle; }
        void set_t_zenith_angle(const EutraCellIdentity & value) { this->t_zenith_angle = value; }
    };

    class TNormalVectorDirection {
        public:
        TNormalVectorDirection() = default;
        virtual ~TNormalVectorDirection() = default;

        private:
        EutraCellIdentityType type;
        TNormalVectorDirectionProperties properties;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const TNormalVectorDirectionProperties & get_properties() const { return properties; }
        TNormalVectorDirectionProperties & get_mutable_properties() { return properties; }
        void set_properties(const TNormalVectorDirectionProperties & value) { this->properties = value; }
    };

    class TxArrayItemProperties {
        public:
        TxArrayItemProperties() = default;
        virtual ~TxArrayItemProperties() = default;

        private:
        EutraCellIdentity t_name;
        GnbCuUpId t_number_of_rows;
        GnbCuUpId t_number_of_columns;
        GnbCuUpId t_number_of_array_layers;
        EutraCellIdentity t_horizontal_spacing;
        EutraCellIdentity t_vertical_spacing;
        TNormalVectorDirection t_normal_vector_direction;
        TLeftmostBottomArrayElementPosition t_leftmost_bottom_array_element_position;
        GEnbIdList t_polarization_list;
        GnbCuUpId t_band_number;
        EutraCellIdentity t_max_gain;
        EutraCellIdentity t_min_gain;
        EutraCellIdentity t_independent_power_budget;

        public:
        const EutraCellIdentity & get_t_name() const { return t_name; }
        EutraCellIdentity & get_mutable_t_name() { return t_name; }
        void set_t_name(const EutraCellIdentity & value) { this->t_name = value; }

        const GnbCuUpId & get_t_number_of_rows() const { return t_number_of_rows; }
        GnbCuUpId & get_mutable_t_number_of_rows() { return t_number_of_rows; }
        void set_t_number_of_rows(const GnbCuUpId & value) { this->t_number_of_rows = value; }

        const GnbCuUpId & get_t_number_of_columns() const { return t_number_of_columns; }
        GnbCuUpId & get_mutable_t_number_of_columns() { return t_number_of_columns; }
        void set_t_number_of_columns(const GnbCuUpId & value) { this->t_number_of_columns = value; }

        const GnbCuUpId & get_t_number_of_array_layers() const { return t_number_of_array_layers; }
        GnbCuUpId & get_mutable_t_number_of_array_layers() { return t_number_of_array_layers; }
        void set_t_number_of_array_layers(const GnbCuUpId & value) { this->t_number_of_array_layers = value; }

        const EutraCellIdentity & get_t_horizontal_spacing() const { return t_horizontal_spacing; }
        EutraCellIdentity & get_mutable_t_horizontal_spacing() { return t_horizontal_spacing; }
        void set_t_horizontal_spacing(const EutraCellIdentity & value) { this->t_horizontal_spacing = value; }

        const EutraCellIdentity & get_t_vertical_spacing() const { return t_vertical_spacing; }
        EutraCellIdentity & get_mutable_t_vertical_spacing() { return t_vertical_spacing; }
        void set_t_vertical_spacing(const EutraCellIdentity & value) { this->t_vertical_spacing = value; }

        const TNormalVectorDirection & get_t_normal_vector_direction() const { return t_normal_vector_direction; }
        TNormalVectorDirection & get_mutable_t_normal_vector_direction() { return t_normal_vector_direction; }
        void set_t_normal_vector_direction(const TNormalVectorDirection & value) { this->t_normal_vector_direction = value; }

        const TLeftmostBottomArrayElementPosition & get_t_leftmost_bottom_array_element_position() const { return t_leftmost_bottom_array_element_position; }
        TLeftmostBottomArrayElementPosition & get_mutable_t_leftmost_bottom_array_element_position() { return t_leftmost_bottom_array_element_position; }
        void set_t_leftmost_bottom_array_element_position(const TLeftmostBottomArrayElementPosition & value) { this->t_leftmost_bottom_array_element_position = value; }

        const GEnbIdList & get_t_polarization_list() const { return t_polarization_list; }
        GEnbIdList & get_mutable_t_polarization_list() { return t_polarization_list; }
        void set_t_polarization_list(const GEnbIdList & value) { this->t_polarization_list = value; }

        const GnbCuUpId & get_t_band_number() const { return t_band_number; }
        GnbCuUpId & get_mutable_t_band_number() { return t_band_number; }
        void set_t_band_number(const GnbCuUpId & value) { this->t_band_number = value; }

        const EutraCellIdentity & get_t_max_gain() const { return t_max_gain; }
        EutraCellIdentity & get_mutable_t_max_gain() { return t_max_gain; }
        void set_t_max_gain(const EutraCellIdentity & value) { this->t_max_gain = value; }

        const EutraCellIdentity & get_t_min_gain() const { return t_min_gain; }
        EutraCellIdentity & get_mutable_t_min_gain() { return t_min_gain; }
        void set_t_min_gain(const EutraCellIdentity & value) { this->t_min_gain = value; }

        const EutraCellIdentity & get_t_independent_power_budget() const { return t_independent_power_budget; }
        EutraCellIdentity & get_mutable_t_independent_power_budget() { return t_independent_power_budget; }
        void set_t_independent_power_budget(const EutraCellIdentity & value) { this->t_independent_power_budget = value; }
    };

    class TxArrayItem {
        public:
        TxArrayItem() = default;
        virtual ~TxArrayItem() = default;

        private:
        EutraCellIdentityType type;
        TxArrayItemProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const TxArrayItemProperties & get_properties() const { return properties; }
        TxArrayItemProperties & get_mutable_properties() { return properties; }
        void set_properties(const TxArrayItemProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class ValuesOfAttributesProperties {
        public:
        ValuesOfAttributesProperties() = default;
        virtual ~ValuesOfAttributesProperties() = default;

        private:
        ItemsElement ran_configuration_structure;

        public:
        const ItemsElement & get_ran_configuration_structure() const { return ran_configuration_structure; }
        ItemsElement & get_mutable_ran_configuration_structure() { return ran_configuration_structure; }
        void set_ran_configuration_structure(const ItemsElement & value) { this->ran_configuration_structure = value; }
    };

    class ValuesOfAttributes {
        public:
        ValuesOfAttributes() = default;
        virtual ~ValuesOfAttributes() = default;

        private:
        EutraCellIdentityType type;
        ValuesOfAttributesProperties properties;
        std::vector<std::string> required;

        public:
        const EutraCellIdentityType & get_type() const { return type; }
        EutraCellIdentityType & get_mutable_type() { return type; }
        void set_type(const EutraCellIdentityType & value) { this->type = value; }

        const ValuesOfAttributesProperties & get_properties() const { return properties; }
        ValuesOfAttributesProperties & get_mutable_properties() { return properties; }
        void set_properties(const ValuesOfAttributesProperties & value) { this->properties = value; }

        const std::vector<std::string> & get_required() const { return required; }
        std::vector<std::string> & get_mutable_required() { return required; }
        void set_required(const std::vector<std::string> & value) { this->required = value; }
    };

    class Schemas {
        public:
        Schemas() = default;
        virtual ~Schemas() = default;

        private:
        GnbCuUpId gnb_id;
        GnbCuUpId gnb_id_length;
        GnbName gnb_name;
        GnbCuUpId gnb_du_id;
        GnbCuUpId gnb_cu_up_id;
        Sst sst;
        Snssai snssai;
        GEnbIdList snssai_list;
        GEnbId mcc;
        GEnbId mnc;
        OGnbCuCpFunction plmn_id;
        GEnbIdList plmn_id_list;
        OGnbCuCpFunction plmn_info;
        GEnbIdList plmn_info_list;
        GEnbId g_gnb_id;
        GEnbId g_enb_id;
        GEnbIdList g_gnb_id_list;
        GEnbIdList g_enb_id_list;
        GnbCuUpId nr_pci;
        GnbCuUpId nr_tac;
        AdministrativeState operational_state;
        AdministrativeState administrative_state;
        AdministrativeState cell_state;
        AdministrativeState cyclic_prefix;
        AdministrativeState bwp_context;
        AdministrativeState is_initial_bwp;
        SsbDuration sub_carrier_spacing;
        SsbDuration ssb_periodicity;
        SsbDuration ssb_duration;
        SsbDuration ssb_sub_carrier_spacing;
        AdministrativeState resource_type;
        OGnbCuCpFunction rrm_policy_member;
        GEnbIdList rrm_policy_member_list;
        The5_QiList the_5_qi_list;
        PartitionFlowList partition_flow_list;
        PartitionList partition_list;
        PrbBlankingConfigurationList prb_blanking_configuration_list;
        EsObjective es_objective;
        PerfObjective perf_objective;
        GEnbIdList perf_objective_list;
        SleepMode sleep_mode;
        GEnbIdList sleep_modes;
        SupportedTrxControlMask supported_trx_control_mask;
        GEnbIdList supported_trx_control_masks;
        EnergySavingCapabilityCommonInfo energy_saving_capability_common_info;
        CapabilityInfo asm_capability_info;
        CapabilityInfo trx_control_capability_info;
        OruCapabilities oru_capabilities;
        OnDurationTimer on_duration_timer;
        CycleStartOffset cycle_start_offset;
        TPolarizationItem t_polarization_item;
        RPolarizationItem r_polarization_item;
        TxArrayItem tx_array_item;
        RxArrayItem rx_array_item;
        GEnbIdList tx_array_list;
        GEnbIdList rx_array_list;
        OruUserPlaneConfiguration oru_user_plane_configuration;
        OGnbCuCpFunction o_gnb_cu_cp_function;
        OGnbCuCpFunction o_gnb_cu_up_function;
        OGnbCuCpFunction o_gnb_du_function;
        ONrCellCu o_nr_cell_cu;
        ONrCellDu o_nr_cell_du;
        ORrmPolicyRatio o_rrm_policy_ratio;
        OBwp o_bwp;
        OCesManagementFunction o_ces_management_function;
        ONesPolicy o_nes_policy;
        OPrbBlankingPolicy o_prb_blanking_policy;
        OCellDtxdrxConfig o_cell_dtxdrx_config;
        ORuInfo o_ru_info;
        ActionDefinitionFormat e2_sm_ccc_ran_configuration_structure;
        RicIndicationHeader ric_indication_header;
        ActionDefinitionFormat indication_header_format;
        E2SmCccIndicationHeaderFormat1 e2_sm_ccc_indication_header_format1;
        RicIndicationMessage ric_indication_message;
        ActionDefinitionFormat indication_message_format;
        E2SmCccIndicationMessageFormat1 e2_sm_ccc_indication_message_format1;
        GEnbIdList list_of_configurations_reported;
        ConfigurationStructure configuration_structure;
        ValuesOfAttributes values_of_attributes;
        E2SmCccIndicationMessageFormat2 e2_sm_ccc_indication_message_format2;
        GEnbIdList list_of_cells_reported;
        CellReported cell_reported;
        CellGlobalId cell_global_id;
        NrCgi nr_cgi;
        GEnbId nr_cell_identity;
        EutraCgi eutra_cgi;
        EutraCellIdentity eutra_cell_identity;
        RicControlHeader ric_control_header;
        ActionDefinitionFormat control_header_format;
        E2SmCccHeaderFormat1 e2_sm_ccc_control_header_format1;
        RicControlMessage ric_control_message;
        ActionDefinitionFormat control_message_format;
        E2SmCccControlMessageFormat1 e2_sm_ccc_control_message_format1;
        GEnbIdList list_of_configuration_structures;
        ConfigurationStructureWrite configuration_structure_write;
        E2SmCccControlMessageFormat2 e2_sm_ccc_control_message_format2;
        GEnbIdList list_of_cells_controlled;
        CellControlled cell_controlled;
        RanFunctionDefinition ran_function_definition;
        RanFunctionName ran_function_name;
        GEnbIdList list_of_supported_ran_configuration_structures;
        RanConfigurationStructure ran_configuration_structure;
        GEnbIdList list_of_supported_attributes;
        Attribute attribute;
        RicServices ric_services;
        EventTrigger event_trigger;
        GEnbIdList list_of_supported_event_trigger_styles;
        EventTriggerStyle event_trigger_style;
        ReportService report_service;
        GEnbIdList list_of_supported_report_styles;
        ReportStyle report_style;
        EventTriggerStyleType event_trigger_style_type;
        EutraCellIdentity insert_service;
        ControlService control_service;
        GEnbIdList list_of_supported_control_styles;
        ControlStyle control_style;
        EutraCellIdentity policy_service;
        QueryService query_service;
        GEnbIdList list_of_supported_query_styles;
        QueryStyle query_style;
        GEnbIdList list_of_cells_for_ran_function_definition;
        CellForRanFunctionDefinition cell_for_ran_function_definition;
        RicEventTriggerDefinition ric_event_trigger_definition;
        ActionDefinitionFormat event_trigger_definition_format;
        E2SmCccEventTriggerDefinitionFormat1 e2_sm_ccc_event_trigger_definition_format1;
        GEnbIdList list_of_ran_configuration_structures_for_event_trigger;
        RanConfigurationStructureForEventTrigger ran_configuration_structure_for_event_trigger;
        E2SmCccEventTriggerDefinitionFormat2 e2_sm_ccc_event_trigger_definition_format2;
        GEnbIdList list_of_cell_level_configuration_structures_for_event_trigger;
        CellLevelConfigurationStructureForEventTrigger cell_level_configuration_structure_for_event_trigger;
        E2SmCccEventTriggerDefinitionFormat3 e2_sm_ccc_event_trigger_definition_format3;
        RicActionDefinition ric_action_definition;
        ActionDefinitionFormat action_definition_format;
        E2SmCccActionDefinitionFormat1 e2_sm_ccc_action_definition_format1;
        GEnbIdList list_of_ran_configuration_structures_for_adf;
        RanConfigurationStructureForAdf ran_configuration_structure_for_adf;
        AttributeName attribute_name;
        E2SmCccActionDefinitionFormat2 e2_sm_ccc_action_definition_format2;
        GEnbIdList list_of_cell_configurations_to_be_reported_for_adf;
        CellConfigurationToBeReportedForAdf cell_configuration_to_be_reported_for_adf;
        RicControlOutcome ric_control_outcome;
        ActionDefinitionFormat control_outcome_format;
        E2SmCccControlOutcomeFormat1 e2_sm_ccc_control_outcome_format1;
        GEnbIdList ran_configuration_structures_accepted_list;
        ConfigurationStructureAccepted configuration_structure_accepted;
        GEnbIdList ran_configuration_structures_failed_list;
        ConfigurationStructureFailed configuration_structure_failed;
        AdministrativeState cause;
        E2SmCccControlOutcomeFormat2 e2_sm_ccc_control_outcome_format2;
        GEnbIdList list_of_cells_for_control_outcome;
        CellControlOutcome cell_control_outcome;
        RicQueryHeader ric_query_header;
        ActionDefinitionFormat query_header_format;
        E2SmCccHeaderFormat1 e2_sm_ccc_query_header_format1;
        RicQueryDefinition ric_query_definition;
        ActionDefinitionFormat query_definition_format;
        E2SmCccQueryDefinitionFormat1 e2_sm_ccc_query_definition_format1;
        GEnbIdList list_of_nodelevel_ran_configuration_structures_for_query;
        ConfigurationStructuresForQuery nodelevel_ran_configuration_structures_for_query;
        E2SmCccQueryDefinitionFormat2 e2_sm_ccc_query_definition_format2;
        GEnbIdList list_of_cells_to_be_queried_for_query;
        CellsToBeQueried cells_to_be_queried;
        GEnbIdList list_of_celllevel_configuration_structures_for_query;
        ConfigurationStructuresForQuery celllevel_configuration_structures_for_query;
        RicQueryOutcome ric_query_outcome;
        ActionDefinitionFormat query_outcome_format;
        E2SmCccQueryOutcomeFormat1 e2_sm_ccc_query_outcome_format1;
        GEnbIdList list_of_configuration_structures_to_be_reported_for_query;
        ConfigurationStructuresToBeReportedForQuery configuration_structures_to_be_reported_for_query;
        E2SmCccQueryOutcomeFormat2 e2_sm_ccc_query_outcome_format2;
        GEnbIdList list_of_cells_to_be_reported_for_query;
        CellsToBeReportedForQuery cells_to_be_reported_for_query;

        public:
        const GnbCuUpId & get_gnb_id() const { return gnb_id; }
        GnbCuUpId & get_mutable_gnb_id() { return gnb_id; }
        void set_gnb_id(const GnbCuUpId & value) { this->gnb_id = value; }

        const GnbCuUpId & get_gnb_id_length() const { return gnb_id_length; }
        GnbCuUpId & get_mutable_gnb_id_length() { return gnb_id_length; }
        void set_gnb_id_length(const GnbCuUpId & value) { this->gnb_id_length = value; }

        const GnbName & get_gnb_name() const { return gnb_name; }
        GnbName & get_mutable_gnb_name() { return gnb_name; }
        void set_gnb_name(const GnbName & value) { this->gnb_name = value; }

        const GnbCuUpId & get_gnb_du_id() const { return gnb_du_id; }
        GnbCuUpId & get_mutable_gnb_du_id() { return gnb_du_id; }
        void set_gnb_du_id(const GnbCuUpId & value) { this->gnb_du_id = value; }

        const GnbCuUpId & get_gnb_cu_up_id() const { return gnb_cu_up_id; }
        GnbCuUpId & get_mutable_gnb_cu_up_id() { return gnb_cu_up_id; }
        void set_gnb_cu_up_id(const GnbCuUpId & value) { this->gnb_cu_up_id = value; }

        const Sst & get_sst() const { return sst; }
        Sst & get_mutable_sst() { return sst; }
        void set_sst(const Sst & value) { this->sst = value; }

        const Snssai & get_snssai() const { return snssai; }
        Snssai & get_mutable_snssai() { return snssai; }
        void set_snssai(const Snssai & value) { this->snssai = value; }

        const GEnbIdList & get_snssai_list() const { return snssai_list; }
        GEnbIdList & get_mutable_snssai_list() { return snssai_list; }
        void set_snssai_list(const GEnbIdList & value) { this->snssai_list = value; }

        const GEnbId & get_mcc() const { return mcc; }
        GEnbId & get_mutable_mcc() { return mcc; }
        void set_mcc(const GEnbId & value) { this->mcc = value; }

        const GEnbId & get_mnc() const { return mnc; }
        GEnbId & get_mutable_mnc() { return mnc; }
        void set_mnc(const GEnbId & value) { this->mnc = value; }

        const OGnbCuCpFunction & get_plmn_id() const { return plmn_id; }
        OGnbCuCpFunction & get_mutable_plmn_id() { return plmn_id; }
        void set_plmn_id(const OGnbCuCpFunction & value) { this->plmn_id = value; }

        const GEnbIdList & get_plmn_id_list() const { return plmn_id_list; }
        GEnbIdList & get_mutable_plmn_id_list() { return plmn_id_list; }
        void set_plmn_id_list(const GEnbIdList & value) { this->plmn_id_list = value; }

        const OGnbCuCpFunction & get_plmn_info() const { return plmn_info; }
        OGnbCuCpFunction & get_mutable_plmn_info() { return plmn_info; }
        void set_plmn_info(const OGnbCuCpFunction & value) { this->plmn_info = value; }

        const GEnbIdList & get_plmn_info_list() const { return plmn_info_list; }
        GEnbIdList & get_mutable_plmn_info_list() { return plmn_info_list; }
        void set_plmn_info_list(const GEnbIdList & value) { this->plmn_info_list = value; }

        const GEnbId & get_g_gnb_id() const { return g_gnb_id; }
        GEnbId & get_mutable_g_gnb_id() { return g_gnb_id; }
        void set_g_gnb_id(const GEnbId & value) { this->g_gnb_id = value; }

        const GEnbId & get_g_enb_id() const { return g_enb_id; }
        GEnbId & get_mutable_g_enb_id() { return g_enb_id; }
        void set_g_enb_id(const GEnbId & value) { this->g_enb_id = value; }

        const GEnbIdList & get_g_gnb_id_list() const { return g_gnb_id_list; }
        GEnbIdList & get_mutable_g_gnb_id_list() { return g_gnb_id_list; }
        void set_g_gnb_id_list(const GEnbIdList & value) { this->g_gnb_id_list = value; }

        const GEnbIdList & get_g_enb_id_list() const { return g_enb_id_list; }
        GEnbIdList & get_mutable_g_enb_id_list() { return g_enb_id_list; }
        void set_g_enb_id_list(const GEnbIdList & value) { this->g_enb_id_list = value; }

        const GnbCuUpId & get_nr_pci() const { return nr_pci; }
        GnbCuUpId & get_mutable_nr_pci() { return nr_pci; }
        void set_nr_pci(const GnbCuUpId & value) { this->nr_pci = value; }

        const GnbCuUpId & get_nr_tac() const { return nr_tac; }
        GnbCuUpId & get_mutable_nr_tac() { return nr_tac; }
        void set_nr_tac(const GnbCuUpId & value) { this->nr_tac = value; }

        const AdministrativeState & get_operational_state() const { return operational_state; }
        AdministrativeState & get_mutable_operational_state() { return operational_state; }
        void set_operational_state(const AdministrativeState & value) { this->operational_state = value; }

        const AdministrativeState & get_administrative_state() const { return administrative_state; }
        AdministrativeState & get_mutable_administrative_state() { return administrative_state; }
        void set_administrative_state(const AdministrativeState & value) { this->administrative_state = value; }

        const AdministrativeState & get_cell_state() const { return cell_state; }
        AdministrativeState & get_mutable_cell_state() { return cell_state; }
        void set_cell_state(const AdministrativeState & value) { this->cell_state = value; }

        const AdministrativeState & get_cyclic_prefix() const { return cyclic_prefix; }
        AdministrativeState & get_mutable_cyclic_prefix() { return cyclic_prefix; }
        void set_cyclic_prefix(const AdministrativeState & value) { this->cyclic_prefix = value; }

        const AdministrativeState & get_bwp_context() const { return bwp_context; }
        AdministrativeState & get_mutable_bwp_context() { return bwp_context; }
        void set_bwp_context(const AdministrativeState & value) { this->bwp_context = value; }

        const AdministrativeState & get_is_initial_bwp() const { return is_initial_bwp; }
        AdministrativeState & get_mutable_is_initial_bwp() { return is_initial_bwp; }
        void set_is_initial_bwp(const AdministrativeState & value) { this->is_initial_bwp = value; }

        const SsbDuration & get_sub_carrier_spacing() const { return sub_carrier_spacing; }
        SsbDuration & get_mutable_sub_carrier_spacing() { return sub_carrier_spacing; }
        void set_sub_carrier_spacing(const SsbDuration & value) { this->sub_carrier_spacing = value; }

        const SsbDuration & get_ssb_periodicity() const { return ssb_periodicity; }
        SsbDuration & get_mutable_ssb_periodicity() { return ssb_periodicity; }
        void set_ssb_periodicity(const SsbDuration & value) { this->ssb_periodicity = value; }

        const SsbDuration & get_ssb_duration() const { return ssb_duration; }
        SsbDuration & get_mutable_ssb_duration() { return ssb_duration; }
        void set_ssb_duration(const SsbDuration & value) { this->ssb_duration = value; }

        const SsbDuration & get_ssb_sub_carrier_spacing() const { return ssb_sub_carrier_spacing; }
        SsbDuration & get_mutable_ssb_sub_carrier_spacing() { return ssb_sub_carrier_spacing; }
        void set_ssb_sub_carrier_spacing(const SsbDuration & value) { this->ssb_sub_carrier_spacing = value; }

        const AdministrativeState & get_resource_type() const { return resource_type; }
        AdministrativeState & get_mutable_resource_type() { return resource_type; }
        void set_resource_type(const AdministrativeState & value) { this->resource_type = value; }

        const OGnbCuCpFunction & get_rrm_policy_member() const { return rrm_policy_member; }
        OGnbCuCpFunction & get_mutable_rrm_policy_member() { return rrm_policy_member; }
        void set_rrm_policy_member(const OGnbCuCpFunction & value) { this->rrm_policy_member = value; }

        const GEnbIdList & get_rrm_policy_member_list() const { return rrm_policy_member_list; }
        GEnbIdList & get_mutable_rrm_policy_member_list() { return rrm_policy_member_list; }
        void set_rrm_policy_member_list(const GEnbIdList & value) { this->rrm_policy_member_list = value; }

        const The5_QiList & get_the_5__qi_list() const { return the_5_qi_list; }
        The5_QiList & get_mutable_the_5__qi_list() { return the_5_qi_list; }
        void set_the_5__qi_list(const The5_QiList & value) { this->the_5_qi_list = value; }

        const PartitionFlowList & get_partition_flow_list() const { return partition_flow_list; }
        PartitionFlowList & get_mutable_partition_flow_list() { return partition_flow_list; }
        void set_partition_flow_list(const PartitionFlowList & value) { this->partition_flow_list = value; }

        const PartitionList & get_partition_list() const { return partition_list; }
        PartitionList & get_mutable_partition_list() { return partition_list; }
        void set_partition_list(const PartitionList & value) { this->partition_list = value; }

        const PrbBlankingConfigurationList & get_prb_blanking_configuration_list() const { return prb_blanking_configuration_list; }
        PrbBlankingConfigurationList & get_mutable_prb_blanking_configuration_list() { return prb_blanking_configuration_list; }
        void set_prb_blanking_configuration_list(const PrbBlankingConfigurationList & value) { this->prb_blanking_configuration_list = value; }

        const EsObjective & get_es_objective() const { return es_objective; }
        EsObjective & get_mutable_es_objective() { return es_objective; }
        void set_es_objective(const EsObjective & value) { this->es_objective = value; }

        const PerfObjective & get_perf_objective() const { return perf_objective; }
        PerfObjective & get_mutable_perf_objective() { return perf_objective; }
        void set_perf_objective(const PerfObjective & value) { this->perf_objective = value; }

        const GEnbIdList & get_perf_objective_list() const { return perf_objective_list; }
        GEnbIdList & get_mutable_perf_objective_list() { return perf_objective_list; }
        void set_perf_objective_list(const GEnbIdList & value) { this->perf_objective_list = value; }

        const SleepMode & get_sleep_mode() const { return sleep_mode; }
        SleepMode & get_mutable_sleep_mode() { return sleep_mode; }
        void set_sleep_mode(const SleepMode & value) { this->sleep_mode = value; }

        const GEnbIdList & get_sleep_modes() const { return sleep_modes; }
        GEnbIdList & get_mutable_sleep_modes() { return sleep_modes; }
        void set_sleep_modes(const GEnbIdList & value) { this->sleep_modes = value; }

        const SupportedTrxControlMask & get_supported_trx_control_mask() const { return supported_trx_control_mask; }
        SupportedTrxControlMask & get_mutable_supported_trx_control_mask() { return supported_trx_control_mask; }
        void set_supported_trx_control_mask(const SupportedTrxControlMask & value) { this->supported_trx_control_mask = value; }

        const GEnbIdList & get_supported_trx_control_masks() const { return supported_trx_control_masks; }
        GEnbIdList & get_mutable_supported_trx_control_masks() { return supported_trx_control_masks; }
        void set_supported_trx_control_masks(const GEnbIdList & value) { this->supported_trx_control_masks = value; }

        const EnergySavingCapabilityCommonInfo & get_energy_saving_capability_common_info() const { return energy_saving_capability_common_info; }
        EnergySavingCapabilityCommonInfo & get_mutable_energy_saving_capability_common_info() { return energy_saving_capability_common_info; }
        void set_energy_saving_capability_common_info(const EnergySavingCapabilityCommonInfo & value) { this->energy_saving_capability_common_info = value; }

        const CapabilityInfo & get_asm_capability_info() const { return asm_capability_info; }
        CapabilityInfo & get_mutable_asm_capability_info() { return asm_capability_info; }
        void set_asm_capability_info(const CapabilityInfo & value) { this->asm_capability_info = value; }

        const CapabilityInfo & get_trx_control_capability_info() const { return trx_control_capability_info; }
        CapabilityInfo & get_mutable_trx_control_capability_info() { return trx_control_capability_info; }
        void set_trx_control_capability_info(const CapabilityInfo & value) { this->trx_control_capability_info = value; }

        const OruCapabilities & get_oru_capabilities() const { return oru_capabilities; }
        OruCapabilities & get_mutable_oru_capabilities() { return oru_capabilities; }
        void set_oru_capabilities(const OruCapabilities & value) { this->oru_capabilities = value; }

        const OnDurationTimer & get_on_duration_timer() const { return on_duration_timer; }
        OnDurationTimer & get_mutable_on_duration_timer() { return on_duration_timer; }
        void set_on_duration_timer(const OnDurationTimer & value) { this->on_duration_timer = value; }

        const CycleStartOffset & get_cycle_start_offset() const { return cycle_start_offset; }
        CycleStartOffset & get_mutable_cycle_start_offset() { return cycle_start_offset; }
        void set_cycle_start_offset(const CycleStartOffset & value) { this->cycle_start_offset = value; }

        const TPolarizationItem & get_t_polarization_item() const { return t_polarization_item; }
        TPolarizationItem & get_mutable_t_polarization_item() { return t_polarization_item; }
        void set_t_polarization_item(const TPolarizationItem & value) { this->t_polarization_item = value; }

        const RPolarizationItem & get_r_polarization_item() const { return r_polarization_item; }
        RPolarizationItem & get_mutable_r_polarization_item() { return r_polarization_item; }
        void set_r_polarization_item(const RPolarizationItem & value) { this->r_polarization_item = value; }

        const TxArrayItem & get_tx_array_item() const { return tx_array_item; }
        TxArrayItem & get_mutable_tx_array_item() { return tx_array_item; }
        void set_tx_array_item(const TxArrayItem & value) { this->tx_array_item = value; }

        const RxArrayItem & get_rx_array_item() const { return rx_array_item; }
        RxArrayItem & get_mutable_rx_array_item() { return rx_array_item; }
        void set_rx_array_item(const RxArrayItem & value) { this->rx_array_item = value; }

        const GEnbIdList & get_tx_array_list() const { return tx_array_list; }
        GEnbIdList & get_mutable_tx_array_list() { return tx_array_list; }
        void set_tx_array_list(const GEnbIdList & value) { this->tx_array_list = value; }

        const GEnbIdList & get_rx_array_list() const { return rx_array_list; }
        GEnbIdList & get_mutable_rx_array_list() { return rx_array_list; }
        void set_rx_array_list(const GEnbIdList & value) { this->rx_array_list = value; }

        const OruUserPlaneConfiguration & get_oru_user_plane_configuration() const { return oru_user_plane_configuration; }
        OruUserPlaneConfiguration & get_mutable_oru_user_plane_configuration() { return oru_user_plane_configuration; }
        void set_oru_user_plane_configuration(const OruUserPlaneConfiguration & value) { this->oru_user_plane_configuration = value; }

        const OGnbCuCpFunction & get_o_gnb_cu_cp_function() const { return o_gnb_cu_cp_function; }
        OGnbCuCpFunction & get_mutable_o_gnb_cu_cp_function() { return o_gnb_cu_cp_function; }
        void set_o_gnb_cu_cp_function(const OGnbCuCpFunction & value) { this->o_gnb_cu_cp_function = value; }

        const OGnbCuCpFunction & get_o_gnb_cu_up_function() const { return o_gnb_cu_up_function; }
        OGnbCuCpFunction & get_mutable_o_gnb_cu_up_function() { return o_gnb_cu_up_function; }
        void set_o_gnb_cu_up_function(const OGnbCuCpFunction & value) { this->o_gnb_cu_up_function = value; }

        const OGnbCuCpFunction & get_o_gnb_du_function() const { return o_gnb_du_function; }
        OGnbCuCpFunction & get_mutable_o_gnb_du_function() { return o_gnb_du_function; }
        void set_o_gnb_du_function(const OGnbCuCpFunction & value) { this->o_gnb_du_function = value; }

        const ONrCellCu & get_o_nr_cell_cu() const { return o_nr_cell_cu; }
        ONrCellCu & get_mutable_o_nr_cell_cu() { return o_nr_cell_cu; }
        void set_o_nr_cell_cu(const ONrCellCu & value) { this->o_nr_cell_cu = value; }

        const ONrCellDu & get_o_nr_cell_du() const { return o_nr_cell_du; }
        ONrCellDu & get_mutable_o_nr_cell_du() { return o_nr_cell_du; }
        void set_o_nr_cell_du(const ONrCellDu & value) { this->o_nr_cell_du = value; }

        const ORrmPolicyRatio & get_o_rrm_policy_ratio() const { return o_rrm_policy_ratio; }
        ORrmPolicyRatio & get_mutable_o_rrm_policy_ratio() { return o_rrm_policy_ratio; }
        void set_o_rrm_policy_ratio(const ORrmPolicyRatio & value) { this->o_rrm_policy_ratio = value; }

        const OBwp & get_o_bwp() const { return o_bwp; }
        OBwp & get_mutable_o_bwp() { return o_bwp; }
        void set_o_bwp(const OBwp & value) { this->o_bwp = value; }

        const OCesManagementFunction & get_o_ces_management_function() const { return o_ces_management_function; }
        OCesManagementFunction & get_mutable_o_ces_management_function() { return o_ces_management_function; }
        void set_o_ces_management_function(const OCesManagementFunction & value) { this->o_ces_management_function = value; }

        const ONesPolicy & get_o_nes_policy() const { return o_nes_policy; }
        ONesPolicy & get_mutable_o_nes_policy() { return o_nes_policy; }
        void set_o_nes_policy(const ONesPolicy & value) { this->o_nes_policy = value; }

        const OPrbBlankingPolicy & get_o_prb_blanking_policy() const { return o_prb_blanking_policy; }
        OPrbBlankingPolicy & get_mutable_o_prb_blanking_policy() { return o_prb_blanking_policy; }
        void set_o_prb_blanking_policy(const OPrbBlankingPolicy & value) { this->o_prb_blanking_policy = value; }

        const OCellDtxdrxConfig & get_o_cell_dtxdrx_config() const { return o_cell_dtxdrx_config; }
        OCellDtxdrxConfig & get_mutable_o_cell_dtxdrx_config() { return o_cell_dtxdrx_config; }
        void set_o_cell_dtxdrx_config(const OCellDtxdrxConfig & value) { this->o_cell_dtxdrx_config = value; }

        const ORuInfo & get_o_ru_info() const { return o_ru_info; }
        ORuInfo & get_mutable_o_ru_info() { return o_ru_info; }
        void set_o_ru_info(const ORuInfo & value) { this->o_ru_info = value; }

        const ActionDefinitionFormat & get_e2_sm_ccc_ran_configuration_structure() const { return e2_sm_ccc_ran_configuration_structure; }
        ActionDefinitionFormat & get_mutable_e2_sm_ccc_ran_configuration_structure() { return e2_sm_ccc_ran_configuration_structure; }
        void set_e2_sm_ccc_ran_configuration_structure(const ActionDefinitionFormat & value) { this->e2_sm_ccc_ran_configuration_structure = value; }

        const RicIndicationHeader & get_ric_indication_header() const { return ric_indication_header; }
        RicIndicationHeader & get_mutable_ric_indication_header() { return ric_indication_header; }
        void set_ric_indication_header(const RicIndicationHeader & value) { this->ric_indication_header = value; }

        const ActionDefinitionFormat & get_indication_header_format() const { return indication_header_format; }
        ActionDefinitionFormat & get_mutable_indication_header_format() { return indication_header_format; }
        void set_indication_header_format(const ActionDefinitionFormat & value) { this->indication_header_format = value; }

        const E2SmCccIndicationHeaderFormat1 & get_e2_sm_ccc_indication_header_format1() const { return e2_sm_ccc_indication_header_format1; }
        E2SmCccIndicationHeaderFormat1 & get_mutable_e2_sm_ccc_indication_header_format1() { return e2_sm_ccc_indication_header_format1; }
        void set_e2_sm_ccc_indication_header_format1(const E2SmCccIndicationHeaderFormat1 & value) { this->e2_sm_ccc_indication_header_format1 = value; }

        const RicIndicationMessage & get_ric_indication_message() const { return ric_indication_message; }
        RicIndicationMessage & get_mutable_ric_indication_message() { return ric_indication_message; }
        void set_ric_indication_message(const RicIndicationMessage & value) { this->ric_indication_message = value; }

        const ActionDefinitionFormat & get_indication_message_format() const { return indication_message_format; }
        ActionDefinitionFormat & get_mutable_indication_message_format() { return indication_message_format; }
        void set_indication_message_format(const ActionDefinitionFormat & value) { this->indication_message_format = value; }

        const E2SmCccIndicationMessageFormat1 & get_e2_sm_ccc_indication_message_format1() const { return e2_sm_ccc_indication_message_format1; }
        E2SmCccIndicationMessageFormat1 & get_mutable_e2_sm_ccc_indication_message_format1() { return e2_sm_ccc_indication_message_format1; }
        void set_e2_sm_ccc_indication_message_format1(const E2SmCccIndicationMessageFormat1 & value) { this->e2_sm_ccc_indication_message_format1 = value; }

        const GEnbIdList & get_list_of_configurations_reported() const { return list_of_configurations_reported; }
        GEnbIdList & get_mutable_list_of_configurations_reported() { return list_of_configurations_reported; }
        void set_list_of_configurations_reported(const GEnbIdList & value) { this->list_of_configurations_reported = value; }

        const ConfigurationStructure & get_configuration_structure() const { return configuration_structure; }
        ConfigurationStructure & get_mutable_configuration_structure() { return configuration_structure; }
        void set_configuration_structure(const ConfigurationStructure & value) { this->configuration_structure = value; }

        const ValuesOfAttributes & get_values_of_attributes() const { return values_of_attributes; }
        ValuesOfAttributes & get_mutable_values_of_attributes() { return values_of_attributes; }
        void set_values_of_attributes(const ValuesOfAttributes & value) { this->values_of_attributes = value; }

        const E2SmCccIndicationMessageFormat2 & get_e2_sm_ccc_indication_message_format2() const { return e2_sm_ccc_indication_message_format2; }
        E2SmCccIndicationMessageFormat2 & get_mutable_e2_sm_ccc_indication_message_format2() { return e2_sm_ccc_indication_message_format2; }
        void set_e2_sm_ccc_indication_message_format2(const E2SmCccIndicationMessageFormat2 & value) { this->e2_sm_ccc_indication_message_format2 = value; }

        const GEnbIdList & get_list_of_cells_reported() const { return list_of_cells_reported; }
        GEnbIdList & get_mutable_list_of_cells_reported() { return list_of_cells_reported; }
        void set_list_of_cells_reported(const GEnbIdList & value) { this->list_of_cells_reported = value; }

        const CellReported & get_cell_reported() const { return cell_reported; }
        CellReported & get_mutable_cell_reported() { return cell_reported; }
        void set_cell_reported(const CellReported & value) { this->cell_reported = value; }

        const CellGlobalId & get_cell_global_id() const { return cell_global_id; }
        CellGlobalId & get_mutable_cell_global_id() { return cell_global_id; }
        void set_cell_global_id(const CellGlobalId & value) { this->cell_global_id = value; }

        const NrCgi & get_nr_cgi() const { return nr_cgi; }
        NrCgi & get_mutable_nr_cgi() { return nr_cgi; }
        void set_nr_cgi(const NrCgi & value) { this->nr_cgi = value; }

        const GEnbId & get_nr_cell_identity() const { return nr_cell_identity; }
        GEnbId & get_mutable_nr_cell_identity() { return nr_cell_identity; }
        void set_nr_cell_identity(const GEnbId & value) { this->nr_cell_identity = value; }

        const EutraCgi & get_eutra_cgi() const { return eutra_cgi; }
        EutraCgi & get_mutable_eutra_cgi() { return eutra_cgi; }
        void set_eutra_cgi(const EutraCgi & value) { this->eutra_cgi = value; }

        const EutraCellIdentity & get_eutra_cell_identity() const { return eutra_cell_identity; }
        EutraCellIdentity & get_mutable_eutra_cell_identity() { return eutra_cell_identity; }
        void set_eutra_cell_identity(const EutraCellIdentity & value) { this->eutra_cell_identity = value; }

        const RicControlHeader & get_ric_control_header() const { return ric_control_header; }
        RicControlHeader & get_mutable_ric_control_header() { return ric_control_header; }
        void set_ric_control_header(const RicControlHeader & value) { this->ric_control_header = value; }

        const ActionDefinitionFormat & get_control_header_format() const { return control_header_format; }
        ActionDefinitionFormat & get_mutable_control_header_format() { return control_header_format; }
        void set_control_header_format(const ActionDefinitionFormat & value) { this->control_header_format = value; }

        const E2SmCccHeaderFormat1 & get_e2_sm_ccc_control_header_format1() const { return e2_sm_ccc_control_header_format1; }
        E2SmCccHeaderFormat1 & get_mutable_e2_sm_ccc_control_header_format1() { return e2_sm_ccc_control_header_format1; }
        void set_e2_sm_ccc_control_header_format1(const E2SmCccHeaderFormat1 & value) { this->e2_sm_ccc_control_header_format1 = value; }

        const RicControlMessage & get_ric_control_message() const { return ric_control_message; }
        RicControlMessage & get_mutable_ric_control_message() { return ric_control_message; }
        void set_ric_control_message(const RicControlMessage & value) { this->ric_control_message = value; }

        const ActionDefinitionFormat & get_control_message_format() const { return control_message_format; }
        ActionDefinitionFormat & get_mutable_control_message_format() { return control_message_format; }
        void set_control_message_format(const ActionDefinitionFormat & value) { this->control_message_format = value; }

        const E2SmCccControlMessageFormat1 & get_e2_sm_ccc_control_message_format1() const { return e2_sm_ccc_control_message_format1; }
        E2SmCccControlMessageFormat1 & get_mutable_e2_sm_ccc_control_message_format1() { return e2_sm_ccc_control_message_format1; }
        void set_e2_sm_ccc_control_message_format1(const E2SmCccControlMessageFormat1 & value) { this->e2_sm_ccc_control_message_format1 = value; }

        const GEnbIdList & get_list_of_configuration_structures() const { return list_of_configuration_structures; }
        GEnbIdList & get_mutable_list_of_configuration_structures() { return list_of_configuration_structures; }
        void set_list_of_configuration_structures(const GEnbIdList & value) { this->list_of_configuration_structures = value; }

        const ConfigurationStructureWrite & get_configuration_structure_write() const { return configuration_structure_write; }
        ConfigurationStructureWrite & get_mutable_configuration_structure_write() { return configuration_structure_write; }
        void set_configuration_structure_write(const ConfigurationStructureWrite & value) { this->configuration_structure_write = value; }

        const E2SmCccControlMessageFormat2 & get_e2_sm_ccc_control_message_format2() const { return e2_sm_ccc_control_message_format2; }
        E2SmCccControlMessageFormat2 & get_mutable_e2_sm_ccc_control_message_format2() { return e2_sm_ccc_control_message_format2; }
        void set_e2_sm_ccc_control_message_format2(const E2SmCccControlMessageFormat2 & value) { this->e2_sm_ccc_control_message_format2 = value; }

        const GEnbIdList & get_list_of_cells_controlled() const { return list_of_cells_controlled; }
        GEnbIdList & get_mutable_list_of_cells_controlled() { return list_of_cells_controlled; }
        void set_list_of_cells_controlled(const GEnbIdList & value) { this->list_of_cells_controlled = value; }

        const CellControlled & get_cell_controlled() const { return cell_controlled; }
        CellControlled & get_mutable_cell_controlled() { return cell_controlled; }
        void set_cell_controlled(const CellControlled & value) { this->cell_controlled = value; }

        const RanFunctionDefinition & get_ran_function_definition() const { return ran_function_definition; }
        RanFunctionDefinition & get_mutable_ran_function_definition() { return ran_function_definition; }
        void set_ran_function_definition(const RanFunctionDefinition & value) { this->ran_function_definition = value; }

        const RanFunctionName & get_ran_function_name() const { return ran_function_name; }
        RanFunctionName & get_mutable_ran_function_name() { return ran_function_name; }
        void set_ran_function_name(const RanFunctionName & value) { this->ran_function_name = value; }

        const GEnbIdList & get_list_of_supported_ran_configuration_structures() const { return list_of_supported_ran_configuration_structures; }
        GEnbIdList & get_mutable_list_of_supported_ran_configuration_structures() { return list_of_supported_ran_configuration_structures; }
        void set_list_of_supported_ran_configuration_structures(const GEnbIdList & value) { this->list_of_supported_ran_configuration_structures = value; }

        const RanConfigurationStructure & get_ran_configuration_structure() const { return ran_configuration_structure; }
        RanConfigurationStructure & get_mutable_ran_configuration_structure() { return ran_configuration_structure; }
        void set_ran_configuration_structure(const RanConfigurationStructure & value) { this->ran_configuration_structure = value; }

        const GEnbIdList & get_list_of_supported_attributes() const { return list_of_supported_attributes; }
        GEnbIdList & get_mutable_list_of_supported_attributes() { return list_of_supported_attributes; }
        void set_list_of_supported_attributes(const GEnbIdList & value) { this->list_of_supported_attributes = value; }

        const Attribute & get_attribute() const { return attribute; }
        Attribute & get_mutable_attribute() { return attribute; }
        void set_attribute(const Attribute & value) { this->attribute = value; }

        const RicServices & get_ric_services() const { return ric_services; }
        RicServices & get_mutable_ric_services() { return ric_services; }
        void set_ric_services(const RicServices & value) { this->ric_services = value; }

        const EventTrigger & get_event_trigger() const { return event_trigger; }
        EventTrigger & get_mutable_event_trigger() { return event_trigger; }
        void set_event_trigger(const EventTrigger & value) { this->event_trigger = value; }

        const GEnbIdList & get_list_of_supported_event_trigger_styles() const { return list_of_supported_event_trigger_styles; }
        GEnbIdList & get_mutable_list_of_supported_event_trigger_styles() { return list_of_supported_event_trigger_styles; }
        void set_list_of_supported_event_trigger_styles(const GEnbIdList & value) { this->list_of_supported_event_trigger_styles = value; }

        const EventTriggerStyle & get_event_trigger_style() const { return event_trigger_style; }
        EventTriggerStyle & get_mutable_event_trigger_style() { return event_trigger_style; }
        void set_event_trigger_style(const EventTriggerStyle & value) { this->event_trigger_style = value; }

        const ReportService & get_report_service() const { return report_service; }
        ReportService & get_mutable_report_service() { return report_service; }
        void set_report_service(const ReportService & value) { this->report_service = value; }

        const GEnbIdList & get_list_of_supported_report_styles() const { return list_of_supported_report_styles; }
        GEnbIdList & get_mutable_list_of_supported_report_styles() { return list_of_supported_report_styles; }
        void set_list_of_supported_report_styles(const GEnbIdList & value) { this->list_of_supported_report_styles = value; }

        const ReportStyle & get_report_style() const { return report_style; }
        ReportStyle & get_mutable_report_style() { return report_style; }
        void set_report_style(const ReportStyle & value) { this->report_style = value; }

        const EventTriggerStyleType & get_event_trigger_style_type() const { return event_trigger_style_type; }
        EventTriggerStyleType & get_mutable_event_trigger_style_type() { return event_trigger_style_type; }
        void set_event_trigger_style_type(const EventTriggerStyleType & value) { this->event_trigger_style_type = value; }

        const EutraCellIdentity & get_insert_service() const { return insert_service; }
        EutraCellIdentity & get_mutable_insert_service() { return insert_service; }
        void set_insert_service(const EutraCellIdentity & value) { this->insert_service = value; }

        const ControlService & get_control_service() const { return control_service; }
        ControlService & get_mutable_control_service() { return control_service; }
        void set_control_service(const ControlService & value) { this->control_service = value; }

        const GEnbIdList & get_list_of_supported_control_styles() const { return list_of_supported_control_styles; }
        GEnbIdList & get_mutable_list_of_supported_control_styles() { return list_of_supported_control_styles; }
        void set_list_of_supported_control_styles(const GEnbIdList & value) { this->list_of_supported_control_styles = value; }

        const ControlStyle & get_control_style() const { return control_style; }
        ControlStyle & get_mutable_control_style() { return control_style; }
        void set_control_style(const ControlStyle & value) { this->control_style = value; }

        const EutraCellIdentity & get_policy_service() const { return policy_service; }
        EutraCellIdentity & get_mutable_policy_service() { return policy_service; }
        void set_policy_service(const EutraCellIdentity & value) { this->policy_service = value; }

        const QueryService & get_query_service() const { return query_service; }
        QueryService & get_mutable_query_service() { return query_service; }
        void set_query_service(const QueryService & value) { this->query_service = value; }

        const GEnbIdList & get_list_of_supported_query_styles() const { return list_of_supported_query_styles; }
        GEnbIdList & get_mutable_list_of_supported_query_styles() { return list_of_supported_query_styles; }
        void set_list_of_supported_query_styles(const GEnbIdList & value) { this->list_of_supported_query_styles = value; }

        const QueryStyle & get_query_style() const { return query_style; }
        QueryStyle & get_mutable_query_style() { return query_style; }
        void set_query_style(const QueryStyle & value) { this->query_style = value; }

        const GEnbIdList & get_list_of_cells_for_ran_function_definition() const { return list_of_cells_for_ran_function_definition; }
        GEnbIdList & get_mutable_list_of_cells_for_ran_function_definition() { return list_of_cells_for_ran_function_definition; }
        void set_list_of_cells_for_ran_function_definition(const GEnbIdList & value) { this->list_of_cells_for_ran_function_definition = value; }

        const CellForRanFunctionDefinition & get_cell_for_ran_function_definition() const { return cell_for_ran_function_definition; }
        CellForRanFunctionDefinition & get_mutable_cell_for_ran_function_definition() { return cell_for_ran_function_definition; }
        void set_cell_for_ran_function_definition(const CellForRanFunctionDefinition & value) { this->cell_for_ran_function_definition = value; }

        const RicEventTriggerDefinition & get_ric_event_trigger_definition() const { return ric_event_trigger_definition; }
        RicEventTriggerDefinition & get_mutable_ric_event_trigger_definition() { return ric_event_trigger_definition; }
        void set_ric_event_trigger_definition(const RicEventTriggerDefinition & value) { this->ric_event_trigger_definition = value; }

        const ActionDefinitionFormat & get_event_trigger_definition_format() const { return event_trigger_definition_format; }
        ActionDefinitionFormat & get_mutable_event_trigger_definition_format() { return event_trigger_definition_format; }
        void set_event_trigger_definition_format(const ActionDefinitionFormat & value) { this->event_trigger_definition_format = value; }

        const E2SmCccEventTriggerDefinitionFormat1 & get_e2_sm_ccc_event_trigger_definition_format1() const { return e2_sm_ccc_event_trigger_definition_format1; }
        E2SmCccEventTriggerDefinitionFormat1 & get_mutable_e2_sm_ccc_event_trigger_definition_format1() { return e2_sm_ccc_event_trigger_definition_format1; }
        void set_e2_sm_ccc_event_trigger_definition_format1(const E2SmCccEventTriggerDefinitionFormat1 & value) { this->e2_sm_ccc_event_trigger_definition_format1 = value; }

        const GEnbIdList & get_list_of_ran_configuration_structures_for_event_trigger() const { return list_of_ran_configuration_structures_for_event_trigger; }
        GEnbIdList & get_mutable_list_of_ran_configuration_structures_for_event_trigger() { return list_of_ran_configuration_structures_for_event_trigger; }
        void set_list_of_ran_configuration_structures_for_event_trigger(const GEnbIdList & value) { this->list_of_ran_configuration_structures_for_event_trigger = value; }

        const RanConfigurationStructureForEventTrigger & get_ran_configuration_structure_for_event_trigger() const { return ran_configuration_structure_for_event_trigger; }
        RanConfigurationStructureForEventTrigger & get_mutable_ran_configuration_structure_for_event_trigger() { return ran_configuration_structure_for_event_trigger; }
        void set_ran_configuration_structure_for_event_trigger(const RanConfigurationStructureForEventTrigger & value) { this->ran_configuration_structure_for_event_trigger = value; }

        const E2SmCccEventTriggerDefinitionFormat2 & get_e2_sm_ccc_event_trigger_definition_format2() const { return e2_sm_ccc_event_trigger_definition_format2; }
        E2SmCccEventTriggerDefinitionFormat2 & get_mutable_e2_sm_ccc_event_trigger_definition_format2() { return e2_sm_ccc_event_trigger_definition_format2; }
        void set_e2_sm_ccc_event_trigger_definition_format2(const E2SmCccEventTriggerDefinitionFormat2 & value) { this->e2_sm_ccc_event_trigger_definition_format2 = value; }

        const GEnbIdList & get_list_of_cell_level_configuration_structures_for_event_trigger() const { return list_of_cell_level_configuration_structures_for_event_trigger; }
        GEnbIdList & get_mutable_list_of_cell_level_configuration_structures_for_event_trigger() { return list_of_cell_level_configuration_structures_for_event_trigger; }
        void set_list_of_cell_level_configuration_structures_for_event_trigger(const GEnbIdList & value) { this->list_of_cell_level_configuration_structures_for_event_trigger = value; }

        const CellLevelConfigurationStructureForEventTrigger & get_cell_level_configuration_structure_for_event_trigger() const { return cell_level_configuration_structure_for_event_trigger; }
        CellLevelConfigurationStructureForEventTrigger & get_mutable_cell_level_configuration_structure_for_event_trigger() { return cell_level_configuration_structure_for_event_trigger; }
        void set_cell_level_configuration_structure_for_event_trigger(const CellLevelConfigurationStructureForEventTrigger & value) { this->cell_level_configuration_structure_for_event_trigger = value; }

        const E2SmCccEventTriggerDefinitionFormat3 & get_e2_sm_ccc_event_trigger_definition_format3() const { return e2_sm_ccc_event_trigger_definition_format3; }
        E2SmCccEventTriggerDefinitionFormat3 & get_mutable_e2_sm_ccc_event_trigger_definition_format3() { return e2_sm_ccc_event_trigger_definition_format3; }
        void set_e2_sm_ccc_event_trigger_definition_format3(const E2SmCccEventTriggerDefinitionFormat3 & value) { this->e2_sm_ccc_event_trigger_definition_format3 = value; }

        const RicActionDefinition & get_ric_action_definition() const { return ric_action_definition; }
        RicActionDefinition & get_mutable_ric_action_definition() { return ric_action_definition; }
        void set_ric_action_definition(const RicActionDefinition & value) { this->ric_action_definition = value; }

        const ActionDefinitionFormat & get_action_definition_format() const { return action_definition_format; }
        ActionDefinitionFormat & get_mutable_action_definition_format() { return action_definition_format; }
        void set_action_definition_format(const ActionDefinitionFormat & value) { this->action_definition_format = value; }

        const E2SmCccActionDefinitionFormat1 & get_e2_sm_ccc_action_definition_format1() const { return e2_sm_ccc_action_definition_format1; }
        E2SmCccActionDefinitionFormat1 & get_mutable_e2_sm_ccc_action_definition_format1() { return e2_sm_ccc_action_definition_format1; }
        void set_e2_sm_ccc_action_definition_format1(const E2SmCccActionDefinitionFormat1 & value) { this->e2_sm_ccc_action_definition_format1 = value; }

        const GEnbIdList & get_list_of_ran_configuration_structures_for_adf() const { return list_of_ran_configuration_structures_for_adf; }
        GEnbIdList & get_mutable_list_of_ran_configuration_structures_for_adf() { return list_of_ran_configuration_structures_for_adf; }
        void set_list_of_ran_configuration_structures_for_adf(const GEnbIdList & value) { this->list_of_ran_configuration_structures_for_adf = value; }

        const RanConfigurationStructureForAdf & get_ran_configuration_structure_for_adf() const { return ran_configuration_structure_for_adf; }
        RanConfigurationStructureForAdf & get_mutable_ran_configuration_structure_for_adf() { return ran_configuration_structure_for_adf; }
        void set_ran_configuration_structure_for_adf(const RanConfigurationStructureForAdf & value) { this->ran_configuration_structure_for_adf = value; }

        const AttributeName & get_attribute_name() const { return attribute_name; }
        AttributeName & get_mutable_attribute_name() { return attribute_name; }
        void set_attribute_name(const AttributeName & value) { this->attribute_name = value; }

        const E2SmCccActionDefinitionFormat2 & get_e2_sm_ccc_action_definition_format2() const { return e2_sm_ccc_action_definition_format2; }
        E2SmCccActionDefinitionFormat2 & get_mutable_e2_sm_ccc_action_definition_format2() { return e2_sm_ccc_action_definition_format2; }
        void set_e2_sm_ccc_action_definition_format2(const E2SmCccActionDefinitionFormat2 & value) { this->e2_sm_ccc_action_definition_format2 = value; }

        const GEnbIdList & get_list_of_cell_configurations_to_be_reported_for_adf() const { return list_of_cell_configurations_to_be_reported_for_adf; }
        GEnbIdList & get_mutable_list_of_cell_configurations_to_be_reported_for_adf() { return list_of_cell_configurations_to_be_reported_for_adf; }
        void set_list_of_cell_configurations_to_be_reported_for_adf(const GEnbIdList & value) { this->list_of_cell_configurations_to_be_reported_for_adf = value; }

        const CellConfigurationToBeReportedForAdf & get_cell_configuration_to_be_reported_for_adf() const { return cell_configuration_to_be_reported_for_adf; }
        CellConfigurationToBeReportedForAdf & get_mutable_cell_configuration_to_be_reported_for_adf() { return cell_configuration_to_be_reported_for_adf; }
        void set_cell_configuration_to_be_reported_for_adf(const CellConfigurationToBeReportedForAdf & value) { this->cell_configuration_to_be_reported_for_adf = value; }

        const RicControlOutcome & get_ric_control_outcome() const { return ric_control_outcome; }
        RicControlOutcome & get_mutable_ric_control_outcome() { return ric_control_outcome; }
        void set_ric_control_outcome(const RicControlOutcome & value) { this->ric_control_outcome = value; }

        const ActionDefinitionFormat & get_control_outcome_format() const { return control_outcome_format; }
        ActionDefinitionFormat & get_mutable_control_outcome_format() { return control_outcome_format; }
        void set_control_outcome_format(const ActionDefinitionFormat & value) { this->control_outcome_format = value; }

        const E2SmCccControlOutcomeFormat1 & get_e2_sm_ccc_control_outcome_format1() const { return e2_sm_ccc_control_outcome_format1; }
        E2SmCccControlOutcomeFormat1 & get_mutable_e2_sm_ccc_control_outcome_format1() { return e2_sm_ccc_control_outcome_format1; }
        void set_e2_sm_ccc_control_outcome_format1(const E2SmCccControlOutcomeFormat1 & value) { this->e2_sm_ccc_control_outcome_format1 = value; }

        const GEnbIdList & get_ran_configuration_structures_accepted_list() const { return ran_configuration_structures_accepted_list; }
        GEnbIdList & get_mutable_ran_configuration_structures_accepted_list() { return ran_configuration_structures_accepted_list; }
        void set_ran_configuration_structures_accepted_list(const GEnbIdList & value) { this->ran_configuration_structures_accepted_list = value; }

        const ConfigurationStructureAccepted & get_configuration_structure_accepted() const { return configuration_structure_accepted; }
        ConfigurationStructureAccepted & get_mutable_configuration_structure_accepted() { return configuration_structure_accepted; }
        void set_configuration_structure_accepted(const ConfigurationStructureAccepted & value) { this->configuration_structure_accepted = value; }

        const GEnbIdList & get_ran_configuration_structures_failed_list() const { return ran_configuration_structures_failed_list; }
        GEnbIdList & get_mutable_ran_configuration_structures_failed_list() { return ran_configuration_structures_failed_list; }
        void set_ran_configuration_structures_failed_list(const GEnbIdList & value) { this->ran_configuration_structures_failed_list = value; }

        const ConfigurationStructureFailed & get_configuration_structure_failed() const { return configuration_structure_failed; }
        ConfigurationStructureFailed & get_mutable_configuration_structure_failed() { return configuration_structure_failed; }
        void set_configuration_structure_failed(const ConfigurationStructureFailed & value) { this->configuration_structure_failed = value; }

        const AdministrativeState & get_cause() const { return cause; }
        AdministrativeState & get_mutable_cause() { return cause; }
        void set_cause(const AdministrativeState & value) { this->cause = value; }

        const E2SmCccControlOutcomeFormat2 & get_e2_sm_ccc_control_outcome_format2() const { return e2_sm_ccc_control_outcome_format2; }
        E2SmCccControlOutcomeFormat2 & get_mutable_e2_sm_ccc_control_outcome_format2() { return e2_sm_ccc_control_outcome_format2; }
        void set_e2_sm_ccc_control_outcome_format2(const E2SmCccControlOutcomeFormat2 & value) { this->e2_sm_ccc_control_outcome_format2 = value; }

        const GEnbIdList & get_list_of_cells_for_control_outcome() const { return list_of_cells_for_control_outcome; }
        GEnbIdList & get_mutable_list_of_cells_for_control_outcome() { return list_of_cells_for_control_outcome; }
        void set_list_of_cells_for_control_outcome(const GEnbIdList & value) { this->list_of_cells_for_control_outcome = value; }

        const CellControlOutcome & get_cell_control_outcome() const { return cell_control_outcome; }
        CellControlOutcome & get_mutable_cell_control_outcome() { return cell_control_outcome; }
        void set_cell_control_outcome(const CellControlOutcome & value) { this->cell_control_outcome = value; }

        const RicQueryHeader & get_ric_query_header() const { return ric_query_header; }
        RicQueryHeader & get_mutable_ric_query_header() { return ric_query_header; }
        void set_ric_query_header(const RicQueryHeader & value) { this->ric_query_header = value; }

        const ActionDefinitionFormat & get_query_header_format() const { return query_header_format; }
        ActionDefinitionFormat & get_mutable_query_header_format() { return query_header_format; }
        void set_query_header_format(const ActionDefinitionFormat & value) { this->query_header_format = value; }

        const E2SmCccHeaderFormat1 & get_e2_sm_ccc_query_header_format1() const { return e2_sm_ccc_query_header_format1; }
        E2SmCccHeaderFormat1 & get_mutable_e2_sm_ccc_query_header_format1() { return e2_sm_ccc_query_header_format1; }
        void set_e2_sm_ccc_query_header_format1(const E2SmCccHeaderFormat1 & value) { this->e2_sm_ccc_query_header_format1 = value; }

        const RicQueryDefinition & get_ric_query_definition() const { return ric_query_definition; }
        RicQueryDefinition & get_mutable_ric_query_definition() { return ric_query_definition; }
        void set_ric_query_definition(const RicQueryDefinition & value) { this->ric_query_definition = value; }

        const ActionDefinitionFormat & get_query_definition_format() const { return query_definition_format; }
        ActionDefinitionFormat & get_mutable_query_definition_format() { return query_definition_format; }
        void set_query_definition_format(const ActionDefinitionFormat & value) { this->query_definition_format = value; }

        const E2SmCccQueryDefinitionFormat1 & get_e2_sm_ccc_query_definition_format1() const { return e2_sm_ccc_query_definition_format1; }
        E2SmCccQueryDefinitionFormat1 & get_mutable_e2_sm_ccc_query_definition_format1() { return e2_sm_ccc_query_definition_format1; }
        void set_e2_sm_ccc_query_definition_format1(const E2SmCccQueryDefinitionFormat1 & value) { this->e2_sm_ccc_query_definition_format1 = value; }

        const GEnbIdList & get_list_of_nodelevel_ran_configuration_structures_for_query() const { return list_of_nodelevel_ran_configuration_structures_for_query; }
        GEnbIdList & get_mutable_list_of_nodelevel_ran_configuration_structures_for_query() { return list_of_nodelevel_ran_configuration_structures_for_query; }
        void set_list_of_nodelevel_ran_configuration_structures_for_query(const GEnbIdList & value) { this->list_of_nodelevel_ran_configuration_structures_for_query = value; }

        const ConfigurationStructuresForQuery & get_nodelevel_ran_configuration_structures_for_query() const { return nodelevel_ran_configuration_structures_for_query; }
        ConfigurationStructuresForQuery & get_mutable_nodelevel_ran_configuration_structures_for_query() { return nodelevel_ran_configuration_structures_for_query; }
        void set_nodelevel_ran_configuration_structures_for_query(const ConfigurationStructuresForQuery & value) { this->nodelevel_ran_configuration_structures_for_query = value; }

        const E2SmCccQueryDefinitionFormat2 & get_e2_sm_ccc_query_definition_format2() const { return e2_sm_ccc_query_definition_format2; }
        E2SmCccQueryDefinitionFormat2 & get_mutable_e2_sm_ccc_query_definition_format2() { return e2_sm_ccc_query_definition_format2; }
        void set_e2_sm_ccc_query_definition_format2(const E2SmCccQueryDefinitionFormat2 & value) { this->e2_sm_ccc_query_definition_format2 = value; }

        const GEnbIdList & get_list_of_cells_to_be_queried_for_query() const { return list_of_cells_to_be_queried_for_query; }
        GEnbIdList & get_mutable_list_of_cells_to_be_queried_for_query() { return list_of_cells_to_be_queried_for_query; }
        void set_list_of_cells_to_be_queried_for_query(const GEnbIdList & value) { this->list_of_cells_to_be_queried_for_query = value; }

        const CellsToBeQueried & get_cells_to_be_queried() const { return cells_to_be_queried; }
        CellsToBeQueried & get_mutable_cells_to_be_queried() { return cells_to_be_queried; }
        void set_cells_to_be_queried(const CellsToBeQueried & value) { this->cells_to_be_queried = value; }

        const GEnbIdList & get_list_of_celllevel_configuration_structures_for_query() const { return list_of_celllevel_configuration_structures_for_query; }
        GEnbIdList & get_mutable_list_of_celllevel_configuration_structures_for_query() { return list_of_celllevel_configuration_structures_for_query; }
        void set_list_of_celllevel_configuration_structures_for_query(const GEnbIdList & value) { this->list_of_celllevel_configuration_structures_for_query = value; }

        const ConfigurationStructuresForQuery & get_celllevel_configuration_structures_for_query() const { return celllevel_configuration_structures_for_query; }
        ConfigurationStructuresForQuery & get_mutable_celllevel_configuration_structures_for_query() { return celllevel_configuration_structures_for_query; }
        void set_celllevel_configuration_structures_for_query(const ConfigurationStructuresForQuery & value) { this->celllevel_configuration_structures_for_query = value; }

        const RicQueryOutcome & get_ric_query_outcome() const { return ric_query_outcome; }
        RicQueryOutcome & get_mutable_ric_query_outcome() { return ric_query_outcome; }
        void set_ric_query_outcome(const RicQueryOutcome & value) { this->ric_query_outcome = value; }

        const ActionDefinitionFormat & get_query_outcome_format() const { return query_outcome_format; }
        ActionDefinitionFormat & get_mutable_query_outcome_format() { return query_outcome_format; }
        void set_query_outcome_format(const ActionDefinitionFormat & value) { this->query_outcome_format = value; }

        const E2SmCccQueryOutcomeFormat1 & get_e2_sm_ccc_query_outcome_format1() const { return e2_sm_ccc_query_outcome_format1; }
        E2SmCccQueryOutcomeFormat1 & get_mutable_e2_sm_ccc_query_outcome_format1() { return e2_sm_ccc_query_outcome_format1; }
        void set_e2_sm_ccc_query_outcome_format1(const E2SmCccQueryOutcomeFormat1 & value) { this->e2_sm_ccc_query_outcome_format1 = value; }

        const GEnbIdList & get_list_of_configuration_structures_to_be_reported_for_query() const { return list_of_configuration_structures_to_be_reported_for_query; }
        GEnbIdList & get_mutable_list_of_configuration_structures_to_be_reported_for_query() { return list_of_configuration_structures_to_be_reported_for_query; }
        void set_list_of_configuration_structures_to_be_reported_for_query(const GEnbIdList & value) { this->list_of_configuration_structures_to_be_reported_for_query = value; }

        const ConfigurationStructuresToBeReportedForQuery & get_configuration_structures_to_be_reported_for_query() const { return configuration_structures_to_be_reported_for_query; }
        ConfigurationStructuresToBeReportedForQuery & get_mutable_configuration_structures_to_be_reported_for_query() { return configuration_structures_to_be_reported_for_query; }
        void set_configuration_structures_to_be_reported_for_query(const ConfigurationStructuresToBeReportedForQuery & value) { this->configuration_structures_to_be_reported_for_query = value; }

        const E2SmCccQueryOutcomeFormat2 & get_e2_sm_ccc_query_outcome_format2() const { return e2_sm_ccc_query_outcome_format2; }
        E2SmCccQueryOutcomeFormat2 & get_mutable_e2_sm_ccc_query_outcome_format2() { return e2_sm_ccc_query_outcome_format2; }
        void set_e2_sm_ccc_query_outcome_format2(const E2SmCccQueryOutcomeFormat2 & value) { this->e2_sm_ccc_query_outcome_format2 = value; }

        const GEnbIdList & get_list_of_cells_to_be_reported_for_query() const { return list_of_cells_to_be_reported_for_query; }
        GEnbIdList & get_mutable_list_of_cells_to_be_reported_for_query() { return list_of_cells_to_be_reported_for_query; }
        void set_list_of_cells_to_be_reported_for_query(const GEnbIdList & value) { this->list_of_cells_to_be_reported_for_query = value; }

        const CellsToBeReportedForQuery & get_cells_to_be_reported_for_query() const { return cells_to_be_reported_for_query; }
        CellsToBeReportedForQuery & get_mutable_cells_to_be_reported_for_query() { return cells_to_be_reported_for_query; }
        void set_cells_to_be_reported_for_query(const CellsToBeReportedForQuery & value) { this->cells_to_be_reported_for_query = value; }
    };

    class Components {
        public:
        Components() = default;
        virtual ~Components() = default;

        private:
        Schemas schemas;

        public:
        const Schemas & get_schemas() const { return schemas; }
        Schemas & get_mutable_schemas() { return schemas; }
        void set_schemas(const Schemas & value) { this->schemas = value; }
    };

    class Info {
        public:
        Info() = default;
        virtual ~Info() = default;

        private:
        std::string title;
        std::string version;
        std::string description;

        public:
        const std::string & get_title() const { return title; }
        std::string & get_mutable_title() { return title; }
        void set_title(const std::string & value) { this->title = value; }

        const std::string & get_version() const { return version; }
        std::string & get_mutable_version() { return version; }
        void set_version(const std::string & value) { this->version = value; }

        const std::string & get_description() const { return description; }
        std::string & get_mutable_description() { return description; }
        void set_description(const std::string & value) { this->description = value; }
    };

    class Paths {
        public:
        Paths() = default;
        virtual ~Paths() = default;

        private:

        public:
    };

    class E2SmCcc {
        public:
        E2SmCcc() = default;
        virtual ~E2SmCcc() = default;

        private:
        std::string openapi;
        Info info;
        Paths paths;
        Components components;

        public:
        const std::string & get_openapi() const { return openapi; }
        std::string & get_mutable_openapi() { return openapi; }
        void set_openapi(const std::string & value) { this->openapi = value; }

        const Info & get_info() const { return info; }
        Info & get_mutable_info() { return info; }
        void set_info(const Info & value) { this->info = value; }

        const Paths & get_paths() const { return paths; }
        Paths & get_mutable_paths() { return paths; }
        void set_paths(const Paths & value) { this->paths = value; }

        const Components & get_components() const { return components; }
        Components & get_mutable_components() { return components; }
        void set_components(const Components & value) { this->components = value; }
    };
}

namespace quicktype {
    void from_json(const json & j, ItemsElement & x);
    void to_json(json & j, const ItemsElement & x);

    void from_json(const json & j, ActionDefinitionFormat & x);
    void to_json(json & j, const ActionDefinitionFormat & x);

    void from_json(const json & j, AdministrativeState & x);
    void to_json(json & j, const AdministrativeState & x);

    void from_json(const json & j, EutraCellIdentity & x);
    void to_json(json & j, const EutraCellIdentity & x);

    void from_json(const json & j, AsmCapabilityInfoProperties & x);
    void to_json(json & j, const AsmCapabilityInfoProperties & x);

    void from_json(const json & j, CapabilityInfo & x);
    void to_json(json & j, const CapabilityInfo & x);

    void from_json(const json & j, AttributeProperties & x);
    void to_json(json & j, const AttributeProperties & x);

    void from_json(const json & j, Attribute & x);
    void to_json(json & j, const Attribute & x);

    void from_json(const json & j, AttributeNameProperties & x);
    void to_json(json & j, const AttributeNameProperties & x);

    void from_json(const json & j, AttributeName & x);
    void to_json(json & j, const AttributeName & x);

    void from_json(const json & j, CellConfigurationToBeReportedForAdfProperties & x);
    void to_json(json & j, const CellConfigurationToBeReportedForAdfProperties & x);

    void from_json(const json & j, CellConfigurationToBeReportedForAdf & x);
    void to_json(json & j, const CellConfigurationToBeReportedForAdf & x);

    void from_json(const json & j, CellControlOutcomeProperties & x);
    void to_json(json & j, const CellControlOutcomeProperties & x);

    void from_json(const json & j, CellControlOutcome & x);
    void to_json(json & j, const CellControlOutcome & x);

    void from_json(const json & j, CellControlledProperties & x);
    void to_json(json & j, const CellControlledProperties & x);

    void from_json(const json & j, CellControlled & x);
    void to_json(json & j, const CellControlled & x);

    void from_json(const json & j, CellForRanFunctionDefinitionProperties & x);
    void to_json(json & j, const CellForRanFunctionDefinitionProperties & x);

    void from_json(const json & j, CellForRanFunctionDefinition & x);
    void to_json(json & j, const CellForRanFunctionDefinition & x);

    void from_json(const json & j, CellGlobalId & x);
    void to_json(json & j, const CellGlobalId & x);

    void from_json(const json & j, CellLevelConfigurationStructureForEventTriggerProperties & x);
    void to_json(json & j, const CellLevelConfigurationStructureForEventTriggerProperties & x);

    void from_json(const json & j, CellLevelConfigurationStructureForEventTrigger & x);
    void to_json(json & j, const CellLevelConfigurationStructureForEventTrigger & x);

    void from_json(const json & j, CellReportedProperties & x);
    void to_json(json & j, const CellReportedProperties & x);

    void from_json(const json & j, CellReported & x);
    void to_json(json & j, const CellReported & x);

    void from_json(const json & j, GEnbIdList & x);
    void to_json(json & j, const GEnbIdList & x);

    void from_json(const json & j, CelllevelConfigurationStructuresForQueryProperties & x);
    void to_json(json & j, const CelllevelConfigurationStructuresForQueryProperties & x);

    void from_json(const json & j, ConfigurationStructuresForQuery & x);
    void to_json(json & j, const ConfigurationStructuresForQuery & x);

    void from_json(const json & j, CellsToBeQueriedProperties & x);
    void to_json(json & j, const CellsToBeQueriedProperties & x);

    void from_json(const json & j, CellsToBeQueried & x);
    void to_json(json & j, const CellsToBeQueried & x);

    void from_json(const json & j, CellsToBeReportedForQueryProperties & x);
    void to_json(json & j, const CellsToBeReportedForQueryProperties & x);

    void from_json(const json & j, CellsToBeReportedForQuery & x);
    void to_json(json & j, const CellsToBeReportedForQuery & x);

    void from_json(const json & j, ChangeType & x);
    void to_json(json & j, const ChangeType & x);

    void from_json(const json & j, ConfigurationStructureProperties & x);
    void to_json(json & j, const ConfigurationStructureProperties & x);

    void from_json(const json & j, ConfigurationStructure & x);
    void to_json(json & j, const ConfigurationStructure & x);

    void from_json(const json & j, ConfigurationStructureAcceptedProperties & x);
    void to_json(json & j, const ConfigurationStructureAcceptedProperties & x);

    void from_json(const json & j, ConfigurationStructureAccepted & x);
    void to_json(json & j, const ConfigurationStructureAccepted & x);

    void from_json(const json & j, ConfigurationStructureFailedProperties & x);
    void to_json(json & j, const ConfigurationStructureFailedProperties & x);

    void from_json(const json & j, ConfigurationStructureFailed & x);
    void to_json(json & j, const ConfigurationStructureFailed & x);

    void from_json(const json & j, ConfigurationStructureWriteProperties & x);
    void to_json(json & j, const ConfigurationStructureWriteProperties & x);

    void from_json(const json & j, ConfigurationStructureWrite & x);
    void to_json(json & j, const ConfigurationStructureWrite & x);

    void from_json(const json & j, ConfigurationStructuresToBeReportedForQueryProperties & x);
    void to_json(json & j, const ConfigurationStructuresToBeReportedForQueryProperties & x);

    void from_json(const json & j, ConfigurationStructuresToBeReportedForQuery & x);
    void to_json(json & j, const ConfigurationStructuresToBeReportedForQuery & x);

    void from_json(const json & j, ControlServiceProperties & x);
    void to_json(json & j, const ControlServiceProperties & x);

    void from_json(const json & j, ControlService & x);
    void to_json(json & j, const ControlService & x);

    void from_json(const json & j, ControlStyleProperties & x);
    void to_json(json & j, const ControlStyleProperties & x);

    void from_json(const json & j, ControlStyle & x);
    void to_json(json & j, const ControlStyle & x);

    void from_json(const json & j, GnbCuUpId & x);
    void to_json(json & j, const GnbCuUpId & x);

    void from_json(const json & j, CycleStartOffsetProperties & x);
    void to_json(json & j, const CycleStartOffsetProperties & x);

    void from_json(const json & j, CycleStartOffset & x);
    void to_json(json & j, const CycleStartOffset & x);

    void from_json(const json & j, E2SmCccActionDefinitionFormat1Properties & x);
    void to_json(json & j, const E2SmCccActionDefinitionFormat1Properties & x);

    void from_json(const json & j, E2SmCccActionDefinitionFormat1 & x);
    void to_json(json & j, const E2SmCccActionDefinitionFormat1 & x);

    void from_json(const json & j, E2SmCccActionDefinitionFormat2Properties & x);
    void to_json(json & j, const E2SmCccActionDefinitionFormat2Properties & x);

    void from_json(const json & j, E2SmCccActionDefinitionFormat2 & x);
    void to_json(json & j, const E2SmCccActionDefinitionFormat2 & x);

    void from_json(const json & j, E2SmCccControlHeaderFormat1Properties & x);
    void to_json(json & j, const E2SmCccControlHeaderFormat1Properties & x);

    void from_json(const json & j, E2SmCccHeaderFormat1 & x);
    void to_json(json & j, const E2SmCccHeaderFormat1 & x);

    void from_json(const json & j, E2SmCccControlMessageFormat1Properties & x);
    void to_json(json & j, const E2SmCccControlMessageFormat1Properties & x);

    void from_json(const json & j, E2SmCccControlMessageFormat1 & x);
    void to_json(json & j, const E2SmCccControlMessageFormat1 & x);

    void from_json(const json & j, E2SmCccControlMessageFormat2Properties & x);
    void to_json(json & j, const E2SmCccControlMessageFormat2Properties & x);

    void from_json(const json & j, E2SmCccControlMessageFormat2 & x);
    void to_json(json & j, const E2SmCccControlMessageFormat2 & x);

    void from_json(const json & j, E2SmCccControlOutcomeFormat1Properties & x);
    void to_json(json & j, const E2SmCccControlOutcomeFormat1Properties & x);

    void from_json(const json & j, E2SmCccControlOutcomeFormat1 & x);
    void to_json(json & j, const E2SmCccControlOutcomeFormat1 & x);

    void from_json(const json & j, E2SmCccControlOutcomeFormat2Properties & x);
    void to_json(json & j, const E2SmCccControlOutcomeFormat2Properties & x);

    void from_json(const json & j, E2SmCccControlOutcomeFormat2 & x);
    void to_json(json & j, const E2SmCccControlOutcomeFormat2 & x);

    void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat1Properties & x);
    void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat1Properties & x);

    void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat1 & x);
    void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat1 & x);

    void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat2Properties & x);
    void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat2Properties & x);

    void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat2 & x);
    void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat2 & x);

    void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat3Properties & x);
    void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat3Properties & x);

    void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat3 & x);
    void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat3 & x);

    void from_json(const json & j, E2SmCccIndicationHeaderFormat1Properties & x);
    void to_json(json & j, const E2SmCccIndicationHeaderFormat1Properties & x);

    void from_json(const json & j, E2SmCccIndicationHeaderFormat1 & x);
    void to_json(json & j, const E2SmCccIndicationHeaderFormat1 & x);

    void from_json(const json & j, E2SmCccIndicationMessageFormat1Properties & x);
    void to_json(json & j, const E2SmCccIndicationMessageFormat1Properties & x);

    void from_json(const json & j, E2SmCccIndicationMessageFormat1 & x);
    void to_json(json & j, const E2SmCccIndicationMessageFormat1 & x);

    void from_json(const json & j, E2SmCccIndicationMessageFormat2Properties & x);
    void to_json(json & j, const E2SmCccIndicationMessageFormat2Properties & x);

    void from_json(const json & j, E2SmCccIndicationMessageFormat2 & x);
    void to_json(json & j, const E2SmCccIndicationMessageFormat2 & x);

    void from_json(const json & j, E2SmCccQueryDefinitionFormat1Properties & x);
    void to_json(json & j, const E2SmCccQueryDefinitionFormat1Properties & x);

    void from_json(const json & j, E2SmCccQueryDefinitionFormat1 & x);
    void to_json(json & j, const E2SmCccQueryDefinitionFormat1 & x);

    void from_json(const json & j, E2SmCccQueryDefinitionFormat2Properties & x);
    void to_json(json & j, const E2SmCccQueryDefinitionFormat2Properties & x);

    void from_json(const json & j, E2SmCccQueryDefinitionFormat2 & x);
    void to_json(json & j, const E2SmCccQueryDefinitionFormat2 & x);

    void from_json(const json & j, E2SmCccQueryOutcomeFormat1Properties & x);
    void to_json(json & j, const E2SmCccQueryOutcomeFormat1Properties & x);

    void from_json(const json & j, E2SmCccQueryOutcomeFormat1 & x);
    void to_json(json & j, const E2SmCccQueryOutcomeFormat1 & x);

    void from_json(const json & j, E2SmCccQueryOutcomeFormat2Properties & x);
    void to_json(json & j, const E2SmCccQueryOutcomeFormat2Properties & x);

    void from_json(const json & j, E2SmCccQueryOutcomeFormat2 & x);
    void to_json(json & j, const E2SmCccQueryOutcomeFormat2 & x);

    void from_json(const json & j, EnergySavingCapabilityCommonInfoProperties & x);
    void to_json(json & j, const EnergySavingCapabilityCommonInfoProperties & x);

    void from_json(const json & j, EnergySavingCapabilityCommonInfo & x);
    void to_json(json & j, const EnergySavingCapabilityCommonInfo & x);

    void from_json(const json & j, OneOfProperties & x);
    void to_json(json & j, const OneOfProperties & x);

    void from_json(const json & j, OneOf & x);
    void to_json(json & j, const OneOf & x);

    void from_json(const json & j, EsObjective & x);
    void to_json(json & j, const EsObjective & x);

    void from_json(const json & j, EutraCgiProperties & x);
    void to_json(json & j, const EutraCgiProperties & x);

    void from_json(const json & j, EutraCgi & x);
    void to_json(json & j, const EutraCgi & x);

    void from_json(const json & j, EventTriggerProperties & x);
    void to_json(json & j, const EventTriggerProperties & x);

    void from_json(const json & j, EventTrigger & x);
    void to_json(json & j, const EventTrigger & x);

    void from_json(const json & j, EventTriggerStyleProperties & x);
    void to_json(json & j, const EventTriggerStyleProperties & x);

    void from_json(const json & j, EventTriggerStyle & x);
    void to_json(json & j, const EventTriggerStyle & x);

    void from_json(const json & j, EventTriggerStyleTypeProperties & x);
    void to_json(json & j, const EventTriggerStyleTypeProperties & x);

    void from_json(const json & j, EventTriggerStyleType & x);
    void to_json(json & j, const EventTriggerStyleType & x);

    void from_json(const json & j, GEnbId & x);
    void to_json(json & j, const GEnbId & x);

    void from_json(const json & j, GnbName & x);
    void to_json(json & j, const GnbName & x);

    void from_json(const json & j, NrCgiProperties & x);
    void to_json(json & j, const NrCgiProperties & x);

    void from_json(const json & j, NrCgi & x);
    void to_json(json & j, const NrCgi & x);

    void from_json(const json & j, OBwpProperties & x);
    void to_json(json & j, const OBwpProperties & x);

    void from_json(const json & j, OBwp & x);
    void to_json(json & j, const OBwp & x);

    void from_json(const json & j, OCellDtxdrxConfigProperties & x);
    void to_json(json & j, const OCellDtxdrxConfigProperties & x);

    void from_json(const json & j, OCellDtxdrxConfig & x);
    void to_json(json & j, const OCellDtxdrxConfig & x);

    void from_json(const json & j, OCesManagementFunctionProperties & x);
    void to_json(json & j, const OCesManagementFunctionProperties & x);

    void from_json(const json & j, OCesManagementFunction & x);
    void to_json(json & j, const OCesManagementFunction & x);

    void from_json(const json & j, OGnbCuCpFunction & x);
    void to_json(json & j, const OGnbCuCpFunction & x);

    void from_json(const json & j, ONesPolicyProperties & x);
    void to_json(json & j, const ONesPolicyProperties & x);

    void from_json(const json & j, ONesPolicy & x);
    void to_json(json & j, const ONesPolicy & x);

    void from_json(const json & j, ONrCellCuProperties & x);
    void to_json(json & j, const ONrCellCuProperties & x);

    void from_json(const json & j, ONrCellCu & x);
    void to_json(json & j, const ONrCellCu & x);

    void from_json(const json & j, ONrCellDuProperties & x);
    void to_json(json & j, const ONrCellDuProperties & x);

    void from_json(const json & j, ONrCellDu & x);
    void to_json(json & j, const ONrCellDu & x);

    void from_json(const json & j, OPrbBlankingPolicyProperties & x);
    void to_json(json & j, const OPrbBlankingPolicyProperties & x);

    void from_json(const json & j, OPrbBlankingPolicy & x);
    void to_json(json & j, const OPrbBlankingPolicy & x);

    void from_json(const json & j, ORrmPolicyRatioProperties & x);
    void to_json(json & j, const ORrmPolicyRatioProperties & x);

    void from_json(const json & j, ORrmPolicyRatio & x);
    void to_json(json & j, const ORrmPolicyRatio & x);

    void from_json(const json & j, ORuInfoProperties & x);
    void to_json(json & j, const ORuInfoProperties & x);

    void from_json(const json & j, ORuInfo & x);
    void to_json(json & j, const ORuInfo & x);

    void from_json(const json & j, OnDurationTimer & x);
    void to_json(json & j, const OnDurationTimer & x);

    void from_json(const json & j, OruCapabilitiesProperties & x);
    void to_json(json & j, const OruCapabilitiesProperties & x);

    void from_json(const json & j, OruCapabilities & x);
    void to_json(json & j, const OruCapabilities & x);

    void from_json(const json & j, OruUserPlaneConfigurationProperties & x);
    void to_json(json & j, const OruUserPlaneConfigurationProperties & x);

    void from_json(const json & j, OruUserPlaneConfiguration & x);
    void to_json(json & j, const OruUserPlaneConfiguration & x);

    void from_json(const json & j, PurpleProperties & x);
    void to_json(json & j, const PurpleProperties & x);

    void from_json(const json & j, PartitionFlowListItems & x);
    void to_json(json & j, const PartitionFlowListItems & x);

    void from_json(const json & j, PartitionFlowList & x);
    void to_json(json & j, const PartitionFlowList & x);

    void from_json(const json & j, FluffyProperties & x);
    void to_json(json & j, const FluffyProperties & x);

    void from_json(const json & j, PartitionListItems & x);
    void to_json(json & j, const PartitionListItems & x);

    void from_json(const json & j, PartitionList & x);
    void to_json(json & j, const PartitionList & x);

    void from_json(const json & j, PerfObjectiveProperties & x);
    void to_json(json & j, const PerfObjectiveProperties & x);

    void from_json(const json & j, PerfObjective & x);
    void to_json(json & j, const PerfObjective & x);

    void from_json(const json & j, NumberOfRBs & x);
    void to_json(json & j, const NumberOfRBs & x);

    void from_json(const json & j, TentacledProperties & x);
    void to_json(json & j, const TentacledProperties & x);

    void from_json(const json & j, PrbBlankingConfigurationListItems & x);
    void to_json(json & j, const PrbBlankingConfigurationListItems & x);

    void from_json(const json & j, PrbBlankingConfigurationList & x);
    void to_json(json & j, const PrbBlankingConfigurationList & x);

    void from_json(const json & j, QueryServiceProperties & x);
    void to_json(json & j, const QueryServiceProperties & x);

    void from_json(const json & j, QueryService & x);
    void to_json(json & j, const QueryService & x);

    void from_json(const json & j, QueryStyleProperties & x);
    void to_json(json & j, const QueryStyleProperties & x);

    void from_json(const json & j, QueryStyle & x);
    void to_json(json & j, const QueryStyle & x);

    void from_json(const json & j, RPolarizationItemProperties & x);
    void to_json(json & j, const RPolarizationItemProperties & x);

    void from_json(const json & j, RPolarizationItem & x);
    void to_json(json & j, const RPolarizationItem & x);

    void from_json(const json & j, RanConfigurationStructureProperties & x);
    void to_json(json & j, const RanConfigurationStructureProperties & x);

    void from_json(const json & j, RanConfigurationStructure & x);
    void to_json(json & j, const RanConfigurationStructure & x);

    void from_json(const json & j, RanConfigurationStructureForAdfProperties & x);
    void to_json(json & j, const RanConfigurationStructureForAdfProperties & x);

    void from_json(const json & j, RanConfigurationStructureForAdf & x);
    void to_json(json & j, const RanConfigurationStructureForAdf & x);

    void from_json(const json & j, The5_QiList & x);
    void to_json(json & j, const The5_QiList & x);

    void from_json(const json & j, RanConfigurationStructureForEventTriggerProperties & x);
    void to_json(json & j, const RanConfigurationStructureForEventTriggerProperties & x);

    void from_json(const json & j, RanConfigurationStructureForEventTrigger & x);
    void to_json(json & j, const RanConfigurationStructureForEventTrigger & x);

    void from_json(const json & j, RanFunctionDefinitionProperties & x);
    void to_json(json & j, const RanFunctionDefinitionProperties & x);

    void from_json(const json & j, RanFunctionDefinition & x);
    void to_json(json & j, const RanFunctionDefinition & x);

    void from_json(const json & j, RanFunctionNameProperties & x);
    void to_json(json & j, const RanFunctionNameProperties & x);

    void from_json(const json & j, RanFunctionName & x);
    void to_json(json & j, const RanFunctionName & x);

    void from_json(const json & j, ReportServiceProperties & x);
    void to_json(json & j, const ReportServiceProperties & x);

    void from_json(const json & j, ReportService & x);
    void to_json(json & j, const ReportService & x);

    void from_json(const json & j, ReportStyleProperties & x);
    void to_json(json & j, const ReportStyleProperties & x);

    void from_json(const json & j, ReportStyle & x);
    void to_json(json & j, const ReportStyle & x);

    void from_json(const json & j, RicActionDefinitionProperties & x);
    void to_json(json & j, const RicActionDefinitionProperties & x);

    void from_json(const json & j, RicActionDefinition & x);
    void to_json(json & j, const RicActionDefinition & x);

    void from_json(const json & j, RicControlHeaderProperties & x);
    void to_json(json & j, const RicControlHeaderProperties & x);

    void from_json(const json & j, RicControlHeader & x);
    void to_json(json & j, const RicControlHeader & x);

    void from_json(const json & j, RicControlMessageProperties & x);
    void to_json(json & j, const RicControlMessageProperties & x);

    void from_json(const json & j, RicControlMessage & x);
    void to_json(json & j, const RicControlMessage & x);

    void from_json(const json & j, RicControlOutcomeProperties & x);
    void to_json(json & j, const RicControlOutcomeProperties & x);

    void from_json(const json & j, RicControlOutcome & x);
    void to_json(json & j, const RicControlOutcome & x);

    void from_json(const json & j, RicEventTriggerDefinitionProperties & x);
    void to_json(json & j, const RicEventTriggerDefinitionProperties & x);

    void from_json(const json & j, RicEventTriggerDefinition & x);
    void to_json(json & j, const RicEventTriggerDefinition & x);

    void from_json(const json & j, RicIndicationHeaderProperties & x);
    void to_json(json & j, const RicIndicationHeaderProperties & x);

    void from_json(const json & j, RicIndicationHeader & x);
    void to_json(json & j, const RicIndicationHeader & x);

    void from_json(const json & j, RicIndicationMessageProperties & x);
    void to_json(json & j, const RicIndicationMessageProperties & x);

    void from_json(const json & j, RicIndicationMessage & x);
    void to_json(json & j, const RicIndicationMessage & x);

    void from_json(const json & j, RicQueryDefinitionProperties & x);
    void to_json(json & j, const RicQueryDefinitionProperties & x);

    void from_json(const json & j, RicQueryDefinition & x);
    void to_json(json & j, const RicQueryDefinition & x);

    void from_json(const json & j, RicQueryHeaderProperties & x);
    void to_json(json & j, const RicQueryHeaderProperties & x);

    void from_json(const json & j, RicQueryHeader & x);
    void to_json(json & j, const RicQueryHeader & x);

    void from_json(const json & j, RicQueryOutcomeProperties & x);
    void to_json(json & j, const RicQueryOutcomeProperties & x);

    void from_json(const json & j, RicQueryOutcome & x);
    void to_json(json & j, const RicQueryOutcome & x);

    void from_json(const json & j, RicServicesProperties & x);
    void to_json(json & j, const RicServicesProperties & x);

    void from_json(const json & j, RicServices & x);
    void to_json(json & j, const RicServices & x);

    void from_json(const json & j, RGainCorrectionRangeProperties & x);
    void to_json(json & j, const RGainCorrectionRangeProperties & x);

    void from_json(const json & j, RGainCorrectionRange & x);
    void to_json(json & j, const RGainCorrectionRange & x);

    void from_json(const json & j, RLeftmostBottomArrayElementPositionProperties & x);
    void to_json(json & j, const RLeftmostBottomArrayElementPositionProperties & x);

    void from_json(const json & j, RLeftmostBottomArrayElementPosition & x);
    void to_json(json & j, const RLeftmostBottomArrayElementPosition & x);

    void from_json(const json & j, RNormalVectorDirectionProperties & x);
    void to_json(json & j, const RNormalVectorDirectionProperties & x);

    void from_json(const json & j, RNormalVectorDirection & x);
    void to_json(json & j, const RNormalVectorDirection & x);

    void from_json(const json & j, RxArrayItemProperties & x);
    void to_json(json & j, const RxArrayItemProperties & x);

    void from_json(const json & j, RxArrayItem & x);
    void to_json(json & j, const RxArrayItem & x);

    void from_json(const json & j, SleepModeProperties & x);
    void to_json(json & j, const SleepModeProperties & x);

    void from_json(const json & j, SleepMode & x);
    void to_json(json & j, const SleepMode & x);

    void from_json(const json & j, SnssaiProperties & x);
    void to_json(json & j, const SnssaiProperties & x);

    void from_json(const json & j, Snssai & x);
    void to_json(json & j, const Snssai & x);

    void from_json(const json & j, SsbDuration & x);
    void to_json(json & j, const SsbDuration & x);

    void from_json(const json & j, Sst & x);
    void to_json(json & j, const Sst & x);

    void from_json(const json & j, SupportedTrxControlMaskProperties & x);
    void to_json(json & j, const SupportedTrxControlMaskProperties & x);

    void from_json(const json & j, SupportedTrxControlMask & x);
    void to_json(json & j, const SupportedTrxControlMask & x);

    void from_json(const json & j, TPolarizationItemProperties & x);
    void to_json(json & j, const TPolarizationItemProperties & x);

    void from_json(const json & j, TPolarizationItem & x);
    void to_json(json & j, const TPolarizationItem & x);

    void from_json(const json & j, TLeftmostBottomArrayElementPositionProperties & x);
    void to_json(json & j, const TLeftmostBottomArrayElementPositionProperties & x);

    void from_json(const json & j, TLeftmostBottomArrayElementPosition & x);
    void to_json(json & j, const TLeftmostBottomArrayElementPosition & x);

    void from_json(const json & j, TNormalVectorDirectionProperties & x);
    void to_json(json & j, const TNormalVectorDirectionProperties & x);

    void from_json(const json & j, TNormalVectorDirection & x);
    void to_json(json & j, const TNormalVectorDirection & x);

    void from_json(const json & j, TxArrayItemProperties & x);
    void to_json(json & j, const TxArrayItemProperties & x);

    void from_json(const json & j, TxArrayItem & x);
    void to_json(json & j, const TxArrayItem & x);

    void from_json(const json & j, ValuesOfAttributesProperties & x);
    void to_json(json & j, const ValuesOfAttributesProperties & x);

    void from_json(const json & j, ValuesOfAttributes & x);
    void to_json(json & j, const ValuesOfAttributes & x);

    void from_json(const json & j, Schemas & x);
    void to_json(json & j, const Schemas & x);

    void from_json(const json & j, Components & x);
    void to_json(json & j, const Components & x);

    void from_json(const json & j, Info & x);
    void to_json(json & j, const Info & x);

    void from_json(const json & j, Paths & x);
    void to_json(json & j, const Paths & x);

    void from_json(const json & j, E2SmCcc & x);
    void to_json(json & j, const E2SmCcc & x);

    void from_json(const json & j, EutraCellIdentityType & x);
    void to_json(json & j, const EutraCellIdentityType & x);

    void from_json(const json & j, The5QiListType & x);
    void to_json(json & j, const The5QiListType & x);

    inline void from_json(const json & j, ItemsElement& x) {
        x.set_ref(j.at("$ref").get<std::string>());
    }

    inline void to_json(json & j, const ItemsElement & x) {
        j = json::object();
        j["$ref"] = x.get_ref();
    }

    inline void from_json(const json & j, ActionDefinitionFormat& x) {
        x.set_one_of(j.at("oneOf").get<std::vector<ItemsElement>>());
    }

    inline void to_json(json & j, const ActionDefinitionFormat & x) {
        j = json::object();
        j["oneOf"] = x.get_one_of();
    }

    inline void from_json(const json & j, AdministrativeState& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_administrative_state_enum(j.at("enum").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const AdministrativeState & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["enum"] = x.get_administrative_state_enum();
    }

    inline void from_json(const json & j, EutraCellIdentity& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
    }

    inline void to_json(json & j, const EutraCellIdentity & x) {
        j = json::object();
        j["type"] = x.get_type();
    }

    inline void from_json(const json & j, AsmCapabilityInfoProperties& x) {
        x.set_sleep_modes(j.at("sleepModes").get<ItemsElement>());
        x.set_defined_duration_sleep_supported(j.at("definedDurationSleepSupported").get<EutraCellIdentity>());
        x.set_undefined_duration_sleep_supported(j.at("undefinedDurationSleepSupported").get<EutraCellIdentity>());
        x.set_supported_trx_control_masks(get_stack_optional<ItemsElement>(j, "supportedTrxControlMasks"));
    }

    inline void to_json(json & j, const AsmCapabilityInfoProperties & x) {
        j = json::object();
        j["sleepModes"] = x.get_sleep_modes();
        j["definedDurationSleepSupported"] = x.get_defined_duration_sleep_supported();
        j["undefinedDurationSleepSupported"] = x.get_undefined_duration_sleep_supported();
        j["supportedTrxControlMasks"] = x.get_supported_trx_control_masks();
    }

    inline void from_json(const json & j, CapabilityInfo& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<AsmCapabilityInfoProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CapabilityInfo & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, AttributeProperties& x) {
        x.set_attribute_name(j.at("attributeName").get<EutraCellIdentity>());
        x.set_supported_services(j.at("supportedServices").get<ItemsElement>());
    }

    inline void to_json(json & j, const AttributeProperties & x) {
        j = json::object();
        j["attributeName"] = x.get_attribute_name();
        j["supportedServices"] = x.get_supported_services();
    }

    inline void from_json(const json & j, Attribute& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<AttributeProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const Attribute & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, AttributeNameProperties& x) {
        x.set_attribute_name(j.at("attributeName").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const AttributeNameProperties & x) {
        j = json::object();
        j["attributeName"] = x.get_attribute_name();
    }

    inline void from_json(const json & j, AttributeName& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<AttributeNameProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const AttributeName & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, CellConfigurationToBeReportedForAdfProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalId").get<ItemsElement>());
        x.set_list_of_cell_level_ran_configuration_structures_for_adf(j.at("listOfCellLevelRANConfigurationStructuresForADF").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellConfigurationToBeReportedForAdfProperties & x) {
        j = json::object();
        j["cellGlobalId"] = x.get_cell_global_id();
        j["listOfCellLevelRANConfigurationStructuresForADF"] = x.get_list_of_cell_level_ran_configuration_structures_for_adf();
    }

    inline void from_json(const json & j, CellConfigurationToBeReportedForAdf& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellConfigurationToBeReportedForAdfProperties>());
    }

    inline void to_json(json & j, const CellConfigurationToBeReportedForAdf & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, CellControlOutcomeProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalId").get<ItemsElement>());
        x.set_ran_configuration_structures_accepted_list(j.at("ranConfigurationStructuresAcceptedList").get<ItemsElement>());
        x.set_ran_configuration_structures_failed_list(j.at("ranConfigurationStructuresFailedList").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellControlOutcomeProperties & x) {
        j = json::object();
        j["cellGlobalId"] = x.get_cell_global_id();
        j["ranConfigurationStructuresAcceptedList"] = x.get_ran_configuration_structures_accepted_list();
        j["ranConfigurationStructuresFailedList"] = x.get_ran_configuration_structures_failed_list();
    }

    inline void from_json(const json & j, CellControlOutcome& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellControlOutcomeProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CellControlOutcome & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, CellControlledProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalId").get<ItemsElement>());
        x.set_list_of_configuration_structures(j.at("listOfConfigurationStructures").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellControlledProperties & x) {
        j = json::object();
        j["cellGlobalId"] = x.get_cell_global_id();
        j["listOfConfigurationStructures"] = x.get_list_of_configuration_structures();
    }

    inline void from_json(const json & j, CellControlled& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellControlledProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CellControlled & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, CellForRanFunctionDefinitionProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalID").get<ItemsElement>());
        x.set_list_of_supported_cell_level_ran_configuration_structures(j.at("listOfSupportedCellLevelRANConfigurationStructures").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellForRanFunctionDefinitionProperties & x) {
        j = json::object();
        j["cellGlobalID"] = x.get_cell_global_id();
        j["listOfSupportedCellLevelRANConfigurationStructures"] = x.get_list_of_supported_cell_level_ran_configuration_structures();
    }

    inline void from_json(const json & j, CellForRanFunctionDefinition& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellForRanFunctionDefinitionProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CellForRanFunctionDefinition & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, CellGlobalId& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_one_of(j.at("oneOf").get<std::vector<ItemsElement>>());
    }

    inline void to_json(json & j, const CellGlobalId & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["oneOf"] = x.get_one_of();
    }

    inline void from_json(const json & j, CellLevelConfigurationStructureForEventTriggerProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalId").get<ItemsElement>());
        x.set_list_of_ran_configuration_structures_for_event_trigger(j.at("listOfRANConfigurationStructuresForEventTrigger").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellLevelConfigurationStructureForEventTriggerProperties & x) {
        j = json::object();
        j["cellGlobalId"] = x.get_cell_global_id();
        j["listOfRANConfigurationStructuresForEventTrigger"] = x.get_list_of_ran_configuration_structures_for_event_trigger();
    }

    inline void from_json(const json & j, CellLevelConfigurationStructureForEventTrigger& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellLevelConfigurationStructureForEventTriggerProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CellLevelConfigurationStructureForEventTrigger & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, CellReportedProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalId").get<ItemsElement>());
        x.set_list_of_configuration_structures_reported(j.at("listOfConfigurationStructuresReported").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellReportedProperties & x) {
        j = json::object();
        j["cellGlobalId"] = x.get_cell_global_id();
        j["listOfConfigurationStructuresReported"] = x.get_list_of_configuration_structures_reported();
    }

    inline void from_json(const json & j, CellReported& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellReportedProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CellReported & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, GEnbIdList& x) {
        x.set_type(j.at("type").get<The5QiListType>());
        x.set_items(j.at("items").get<ItemsElement>());
    }

    inline void to_json(json & j, const GEnbIdList & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["items"] = x.get_items();
    }

    inline void from_json(const json & j, CelllevelConfigurationStructuresForQueryProperties& x) {
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_list_of_attributes(j.at("listOfAttributes").get<GEnbIdList>());
    }

    inline void to_json(json & j, const CelllevelConfigurationStructuresForQueryProperties & x) {
        j = json::object();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["listOfAttributes"] = x.get_list_of_attributes();
    }

    inline void from_json(const json & j, ConfigurationStructuresForQuery& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CelllevelConfigurationStructuresForQueryProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ConfigurationStructuresForQuery & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, CellsToBeQueriedProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalId").get<ItemsElement>());
        x.set_list_of_celllevel_configuration_structures_for_query(j.at("listOfCelllevelConfigurationStructuresForQuery").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellsToBeQueriedProperties & x) {
        j = json::object();
        j["cellGlobalId"] = x.get_cell_global_id();
        j["listOfCelllevelConfigurationStructuresForQuery"] = x.get_list_of_celllevel_configuration_structures_for_query();
    }

    inline void from_json(const json & j, CellsToBeQueried& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellsToBeQueriedProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CellsToBeQueried & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, CellsToBeReportedForQueryProperties& x) {
        x.set_cell_global_id(j.at("cellGlobalId").get<ItemsElement>());
        x.set_list_of_configuration_structures_to_be_reported_for_query(j.at("listOfConfigurationStructuresToBeReportedForQuery").get<ItemsElement>());
    }

    inline void to_json(json & j, const CellsToBeReportedForQueryProperties & x) {
        j = json::object();
        j["cellGlobalId"] = x.get_cell_global_id();
        j["listOfConfigurationStructuresToBeReportedForQuery"] = x.get_list_of_configuration_structures_to_be_reported_for_query();
    }

    inline void from_json(const json & j, CellsToBeReportedForQuery& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CellsToBeReportedForQueryProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const CellsToBeReportedForQuery & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ChangeType& x) {
        x.set_change_type_enum(j.at("enum").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ChangeType & x) {
        j = json::object();
        j["enum"] = x.get_change_type_enum();
    }

    inline void from_json(const json & j, ConfigurationStructureProperties& x) {
        x.set_change_type(j.at("changeType").get<ChangeType>());
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_values_of_attributes(j.at("valuesOfAttributes").get<ItemsElement>());
        x.set_old_values_of_attributes(j.at("oldValuesOfAttributes").get<ItemsElement>());
    }

    inline void to_json(json & j, const ConfigurationStructureProperties & x) {
        j = json::object();
        j["changeType"] = x.get_change_type();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["valuesOfAttributes"] = x.get_values_of_attributes();
        j["oldValuesOfAttributes"] = x.get_old_values_of_attributes();
    }

    inline void from_json(const json & j, ConfigurationStructure& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ConfigurationStructureProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ConfigurationStructure & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ConfigurationStructureAcceptedProperties& x) {
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_old_values_of_attributes(j.at("oldValuesOfAttributes").get<ItemsElement>());
        x.set_current_values_of_attributes(j.at("currentValuesOfAttributes").get<ItemsElement>());
        x.set_applied_timestamp(j.at("appliedTimestamp").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const ConfigurationStructureAcceptedProperties & x) {
        j = json::object();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["oldValuesOfAttributes"] = x.get_old_values_of_attributes();
        j["currentValuesOfAttributes"] = x.get_current_values_of_attributes();
        j["appliedTimestamp"] = x.get_applied_timestamp();
    }

    inline void from_json(const json & j, ConfigurationStructureAccepted& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ConfigurationStructureAcceptedProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ConfigurationStructureAccepted & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ConfigurationStructureFailedProperties& x) {
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_old_values_of_attributes(j.at("oldValuesOfAttributes").get<ItemsElement>());
        x.set_requested_values_of_attributes(j.at("requestedValuesOfAttributes").get<ItemsElement>());
        x.set_cause(j.at("cause").get<ItemsElement>());
    }

    inline void to_json(json & j, const ConfigurationStructureFailedProperties & x) {
        j = json::object();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["oldValuesOfAttributes"] = x.get_old_values_of_attributes();
        j["requestedValuesOfAttributes"] = x.get_requested_values_of_attributes();
        j["cause"] = x.get_cause();
    }

    inline void from_json(const json & j, ConfigurationStructureFailed& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ConfigurationStructureFailedProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ConfigurationStructureFailed & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ConfigurationStructureWriteProperties& x) {
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_old_values_of_attributes(j.at("oldValuesOfAttributes").get<ItemsElement>());
        x.set_new_values_of_attributes(j.at("newValuesOfAttributes").get<ItemsElement>());
    }

    inline void to_json(json & j, const ConfigurationStructureWriteProperties & x) {
        j = json::object();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["oldValuesOfAttributes"] = x.get_old_values_of_attributes();
        j["newValuesOfAttributes"] = x.get_new_values_of_attributes();
    }

    inline void from_json(const json & j, ConfigurationStructureWrite& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ConfigurationStructureWriteProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ConfigurationStructureWrite & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ConfigurationStructuresToBeReportedForQueryProperties& x) {
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_values_of_attributes(j.at("valuesOfAttributes").get<ItemsElement>());
    }

    inline void to_json(json & j, const ConfigurationStructuresToBeReportedForQueryProperties & x) {
        j = json::object();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["valuesOfAttributes"] = x.get_values_of_attributes();
    }

    inline void from_json(const json & j, ConfigurationStructuresToBeReportedForQuery& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ConfigurationStructuresToBeReportedForQueryProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ConfigurationStructuresToBeReportedForQuery & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ControlServiceProperties& x) {
        x.set_list_of_supported_control_styles(j.at("listOfSupportedControlStyles").get<ItemsElement>());
    }

    inline void to_json(json & j, const ControlServiceProperties & x) {
        j = json::object();
        j["listOfSupportedControlStyles"] = x.get_list_of_supported_control_styles();
    }

    inline void from_json(const json & j, ControlService& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ControlServiceProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ControlService & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ControlStyleProperties& x) {
        x.set_control_service_style_type(j.at("controlServiceStyleType").get<EutraCellIdentity>());
        x.set_control_service_style_name(j.at("controlServiceStyleName").get<EutraCellIdentity>());
        x.set_control_service_header_format_type(j.at("controlServiceHeaderFormatType").get<EutraCellIdentity>());
        x.set_control_service_message_format_type(j.at("controlServiceMessageFormatType").get<EutraCellIdentity>());
        x.set_ric_call_process_id_format_type(j.at("ricCallProcessIDFormatType").get<EutraCellIdentity>());
        x.set_control_service_control_outcome_format_type(j.at("controlServiceControlOutcomeFormatType").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const ControlStyleProperties & x) {
        j = json::object();
        j["controlServiceStyleType"] = x.get_control_service_style_type();
        j["controlServiceStyleName"] = x.get_control_service_style_name();
        j["controlServiceHeaderFormatType"] = x.get_control_service_header_format_type();
        j["controlServiceMessageFormatType"] = x.get_control_service_message_format_type();
        j["ricCallProcessIDFormatType"] = x.get_ric_call_process_id_format_type();
        j["controlServiceControlOutcomeFormatType"] = x.get_control_service_control_outcome_format_type();
    }

    inline void from_json(const json & j, ControlStyle& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ControlStyleProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ControlStyle & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, GnbCuUpId& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_minimum(get_stack_optional<int64_t>(j, "minimum"));
        x.set_maximum(get_stack_optional<int64_t>(j, "maximum"));
        x.set_gnb_cu_up_id_enum(get_stack_optional<std::vector<std::string>>(j, "enum"));
    }

    inline void to_json(json & j, const GnbCuUpId & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["minimum"] = x.get_minimum();
        j["maximum"] = x.get_maximum();
        j["enum"] = x.get_gnb_cu_up_id_enum();
    }

    inline void from_json(const json & j, CycleStartOffsetProperties& x) {
        x.set_periodicity(j.at("periodicity").get<AdministrativeState>());
        x.set_offset(j.at("offset").get<GnbCuUpId>());
    }

    inline void to_json(json & j, const CycleStartOffsetProperties & x) {
        j = json::object();
        j["periodicity"] = x.get_periodicity();
        j["offset"] = x.get_offset();
    }

    inline void from_json(const json & j, CycleStartOffset& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<CycleStartOffsetProperties>());
    }

    inline void to_json(json & j, const CycleStartOffset & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, E2SmCccActionDefinitionFormat1Properties& x) {
        x.set_list_of_node_level_ran_configuration_structures_for_adf(j.at("listOfNodeLevelRANConfigurationStructuresForADF").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccActionDefinitionFormat1Properties & x) {
        j = json::object();
        j["listOfNodeLevelRANConfigurationStructuresForADF"] = x.get_list_of_node_level_ran_configuration_structures_for_adf();
    }

    inline void from_json(const json & j, E2SmCccActionDefinitionFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccActionDefinitionFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccActionDefinitionFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccActionDefinitionFormat2Properties& x) {
        x.set_list_of_cell_configurations_to_be_reported_for_adf(j.at("listOfCellConfigurationsToBeReportedForADF").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccActionDefinitionFormat2Properties & x) {
        j = json::object();
        j["listOfCellConfigurationsToBeReportedForADF"] = x.get_list_of_cell_configurations_to_be_reported_for_adf();
    }

    inline void from_json(const json & j, E2SmCccActionDefinitionFormat2& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccActionDefinitionFormat2Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccActionDefinitionFormat2 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccControlHeaderFormat1Properties& x) {
        x.set_ric_style_type(j.at("ricStyleType").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const E2SmCccControlHeaderFormat1Properties & x) {
        j = json::object();
        j["ricStyleType"] = x.get_ric_style_type();
    }

    inline void from_json(const json & j, E2SmCccHeaderFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccControlHeaderFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccHeaderFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccControlMessageFormat1Properties& x) {
        x.set_list_of_configuration_structures(j.at("listOfConfigurationStructures").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccControlMessageFormat1Properties & x) {
        j = json::object();
        j["listOfConfigurationStructures"] = x.get_list_of_configuration_structures();
    }

    inline void from_json(const json & j, E2SmCccControlMessageFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccControlMessageFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccControlMessageFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccControlMessageFormat2Properties& x) {
        x.set_list_of_cells_controlled(j.at("listOfCellsControlled").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccControlMessageFormat2Properties & x) {
        j = json::object();
        j["listOfCellsControlled"] = x.get_list_of_cells_controlled();
    }

    inline void from_json(const json & j, E2SmCccControlMessageFormat2& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccControlMessageFormat2Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccControlMessageFormat2 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccControlOutcomeFormat1Properties& x) {
        x.set_received_timestamp(j.at("receivedTimestamp").get<EutraCellIdentity>());
        x.set_ran_configuration_structures_accepted_list(j.at("ranConfigurationStructuresAcceptedList").get<ItemsElement>());
        x.set_ran_configuration_structures_failed_list(j.at("ranConfigurationStructuresFailedList").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccControlOutcomeFormat1Properties & x) {
        j = json::object();
        j["receivedTimestamp"] = x.get_received_timestamp();
        j["ranConfigurationStructuresAcceptedList"] = x.get_ran_configuration_structures_accepted_list();
        j["ranConfigurationStructuresFailedList"] = x.get_ran_configuration_structures_failed_list();
    }

    inline void from_json(const json & j, E2SmCccControlOutcomeFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccControlOutcomeFormat1Properties>());
    }

    inline void to_json(json & j, const E2SmCccControlOutcomeFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, E2SmCccControlOutcomeFormat2Properties& x) {
        x.set_received_timestamp(j.at("receivedTimestamp").get<EutraCellIdentity>());
        x.set_list_of_cells_for_control_outcome(j.at("listOfCellsForControlOutcome").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccControlOutcomeFormat2Properties & x) {
        j = json::object();
        j["receivedTimestamp"] = x.get_received_timestamp();
        j["listOfCellsForControlOutcome"] = x.get_list_of_cells_for_control_outcome();
    }

    inline void from_json(const json & j, E2SmCccControlOutcomeFormat2& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccControlOutcomeFormat2Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccControlOutcomeFormat2 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat1Properties& x) {
        x.set_list_of_node_level_configuration_structures_for_event_trigger(j.at("listOfNodeLevelConfigurationStructuresForEventTrigger").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat1Properties & x) {
        j = json::object();
        j["listOfNodeLevelConfigurationStructuresForEventTrigger"] = x.get_list_of_node_level_configuration_structures_for_event_trigger();
    }

    inline void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccEventTriggerDefinitionFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat2Properties& x) {
        x.set_list_of_cell_level_configuration_structures_for_event_trigger(j.at("listOfCellLevelConfigurationStructuresForEventTrigger").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat2Properties & x) {
        j = json::object();
        j["listOfCellLevelConfigurationStructuresForEventTrigger"] = x.get_list_of_cell_level_configuration_structures_for_event_trigger();
    }

    inline void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat2& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccEventTriggerDefinitionFormat2Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat2 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat3Properties& x) {
        x.set_period(j.at("period").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat3Properties & x) {
        j = json::object();
        j["period"] = x.get_period();
    }

    inline void from_json(const json & j, E2SmCccEventTriggerDefinitionFormat3& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccEventTriggerDefinitionFormat3Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccEventTriggerDefinitionFormat3 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccIndicationHeaderFormat1Properties& x) {
        x.set_indication_reason(j.at("indicationReason").get<ChangeType>());
        x.set_event_time(j.at("eventTime").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const E2SmCccIndicationHeaderFormat1Properties & x) {
        j = json::object();
        j["indicationReason"] = x.get_indication_reason();
        j["eventTime"] = x.get_event_time();
    }

    inline void from_json(const json & j, E2SmCccIndicationHeaderFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccIndicationHeaderFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccIndicationHeaderFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccIndicationMessageFormat1Properties& x) {
        x.set_list_of_configuration_structures_reported(j.at("listOfConfigurationStructuresReported").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccIndicationMessageFormat1Properties & x) {
        j = json::object();
        j["listOfConfigurationStructuresReported"] = x.get_list_of_configuration_structures_reported();
    }

    inline void from_json(const json & j, E2SmCccIndicationMessageFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccIndicationMessageFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccIndicationMessageFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccIndicationMessageFormat2Properties& x) {
        x.set_list_of_cells_reported(j.at("listOfCellsReported").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccIndicationMessageFormat2Properties & x) {
        j = json::object();
        j["listOfCellsReported"] = x.get_list_of_cells_reported();
    }

    inline void from_json(const json & j, E2SmCccIndicationMessageFormat2& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccIndicationMessageFormat2Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccIndicationMessageFormat2 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccQueryDefinitionFormat1Properties& x) {
        x.set_list_of_nodelevel_ran_configuration_structures_for_query(j.at("listOfNodelevelRanConfigurationStructuresForQuery").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccQueryDefinitionFormat1Properties & x) {
        j = json::object();
        j["listOfNodelevelRanConfigurationStructuresForQuery"] = x.get_list_of_nodelevel_ran_configuration_structures_for_query();
    }

    inline void from_json(const json & j, E2SmCccQueryDefinitionFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccQueryDefinitionFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccQueryDefinitionFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccQueryDefinitionFormat2Properties& x) {
        x.set_list_of_cells_to_be_queried_for_query(j.at("listOfCellsToBeQueriedForQuery").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccQueryDefinitionFormat2Properties & x) {
        j = json::object();
        j["listOfCellsToBeQueriedForQuery"] = x.get_list_of_cells_to_be_queried_for_query();
    }

    inline void from_json(const json & j, E2SmCccQueryDefinitionFormat2& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccQueryDefinitionFormat2Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccQueryDefinitionFormat2 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccQueryOutcomeFormat1Properties& x) {
        x.set_list_of_configuration_structures_to_be_reported_for_query(j.at("listOfConfigurationStructuresToBeReportedForQuery").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccQueryOutcomeFormat1Properties & x) {
        j = json::object();
        j["listOfConfigurationStructuresToBeReportedForQuery"] = x.get_list_of_configuration_structures_to_be_reported_for_query();
    }

    inline void from_json(const json & j, E2SmCccQueryOutcomeFormat1& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccQueryOutcomeFormat1Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccQueryOutcomeFormat1 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, E2SmCccQueryOutcomeFormat2Properties& x) {
        x.set_list_of_cells_to_be_reported_for_query(j.at("listOfCellsToBeReportedForQuery").get<ItemsElement>());
    }

    inline void to_json(json & j, const E2SmCccQueryOutcomeFormat2Properties & x) {
        j = json::object();
        j["listOfCellsToBeReportedForQuery"] = x.get_list_of_cells_to_be_reported_for_query();
    }

    inline void from_json(const json & j, E2SmCccQueryOutcomeFormat2& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<E2SmCccQueryOutcomeFormat2Properties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const E2SmCccQueryOutcomeFormat2 & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, EnergySavingCapabilityCommonInfoProperties& x) {
        x.set_st8_ready_message_supported(j.at("ST8-ready-message-supported").get<EutraCellIdentity>());
        x.set_sleep_duration_extension_supported(j.at("sleep-duration-extension-supported").get<EutraCellIdentity>());
        x.set_emergency_wake_up_command_supported(j.at("emergency-wake-up-command-supported").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const EnergySavingCapabilityCommonInfoProperties & x) {
        j = json::object();
        j["ST8-ready-message-supported"] = x.get_st8_ready_message_supported();
        j["sleep-duration-extension-supported"] = x.get_sleep_duration_extension_supported();
        j["emergency-wake-up-command-supported"] = x.get_emergency_wake_up_command_supported();
    }

    inline void from_json(const json & j, EnergySavingCapabilityCommonInfo& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<EnergySavingCapabilityCommonInfoProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const EnergySavingCapabilityCommonInfo & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, OneOfProperties& x) {
        x.set_target_ec(get_stack_optional<EutraCellIdentity>(j, "targetEc"));
        x.set_es_percentage(get_stack_optional<GnbCuUpId>(j, "esPercentage"));
    }

    inline void to_json(json & j, const OneOfProperties & x) {
        j = json::object();
        j["targetEc"] = x.get_target_ec();
        j["esPercentage"] = x.get_es_percentage();
    }

    inline void from_json(const json & j, OneOf& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<OneOfProperties>());
    }

    inline void to_json(json & j, const OneOf & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, EsObjective& x) {
        x.set_one_of(j.at("oneOf").get<std::vector<OneOf>>());
    }

    inline void to_json(json & j, const EsObjective & x) {
        j = json::object();
        j["oneOf"] = x.get_one_of();
    }

    inline void from_json(const json & j, EutraCgiProperties& x) {
        x.set_plmn_identity(j.at("plmnIdentity").get<ItemsElement>());
        x.set_e_utra_cell_identity(j.at("eUTRACellIdentity").get<ItemsElement>());
    }

    inline void to_json(json & j, const EutraCgiProperties & x) {
        j = json::object();
        j["plmnIdentity"] = x.get_plmn_identity();
        j["eUTRACellIdentity"] = x.get_e_utra_cell_identity();
    }

    inline void from_json(const json & j, EutraCgi& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<EutraCgiProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const EutraCgi & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, EventTriggerProperties& x) {
        x.set_list_of_supported_event_trigger_styles(j.at("listOfSupportedEventTriggerStyles").get<ItemsElement>());
    }

    inline void to_json(json & j, const EventTriggerProperties & x) {
        j = json::object();
        j["listOfSupportedEventTriggerStyles"] = x.get_list_of_supported_event_trigger_styles();
    }

    inline void from_json(const json & j, EventTrigger& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<EventTriggerProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const EventTrigger & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, EventTriggerStyleProperties& x) {
        x.set_event_trigger_style_type(j.at("eventTriggerStyleType").get<EutraCellIdentity>());
        x.set_event_trigger_style_name(j.at("eventTriggerStyleName").get<EutraCellIdentity>());
        x.set_event_trigger_format_type(j.at("eventTriggerFormatType").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const EventTriggerStyleProperties & x) {
        j = json::object();
        j["eventTriggerStyleType"] = x.get_event_trigger_style_type();
        j["eventTriggerStyleName"] = x.get_event_trigger_style_name();
        j["eventTriggerFormatType"] = x.get_event_trigger_format_type();
    }

    inline void from_json(const json & j, EventTriggerStyle& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<EventTriggerStyleProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const EventTriggerStyle & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, EventTriggerStyleTypeProperties& x) {
        x.set_event_trigger_style_type(j.at("eventTriggerStyleType").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const EventTriggerStyleTypeProperties & x) {
        j = json::object();
        j["eventTriggerStyleType"] = x.get_event_trigger_style_type();
    }

    inline void from_json(const json & j, EventTriggerStyleType& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<EventTriggerStyleTypeProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const EventTriggerStyleType & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, GEnbId& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_pattern(j.at("pattern").get<std::string>());
    }

    inline void to_json(json & j, const GEnbId & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["pattern"] = x.get_pattern();
    }

    inline void from_json(const json & j, GnbName& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_max_length(j.at("maxLength").get<int64_t>());
    }

    inline void to_json(json & j, const GnbName & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["maxLength"] = x.get_max_length();
    }

    inline void from_json(const json & j, NrCgiProperties& x) {
        x.set_plmn_identity(j.at("plmnIdentity").get<ItemsElement>());
        x.set_n_r_cell_identity(j.at("nRCellIdentity").get<ItemsElement>());
    }

    inline void to_json(json & j, const NrCgiProperties & x) {
        j = json::object();
        j["plmnIdentity"] = x.get_plmn_identity();
        j["nRCellIdentity"] = x.get_n_r_cell_identity();
    }

    inline void from_json(const json & j, NrCgi& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<NrCgiProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const NrCgi & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, OBwpProperties& x) {
        x.set_bwp_context(j.at("bwpContext").get<ItemsElement>());
        x.set_is_initial_bwp(j.at("isInitialBwp").get<ItemsElement>());
        x.set_sub_carrier_spacing(j.at("subCarrierSpacing").get<ItemsElement>());
        x.set_cyclic_prefix(j.at("cyclicPrefix").get<ItemsElement>());
        x.set_start_rb(j.at("startRB").get<EutraCellIdentity>());
        x.set_number_of_r_bs(j.at("numberOfRBs").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const OBwpProperties & x) {
        j = json::object();
        j["bwpContext"] = x.get_bwp_context();
        j["isInitialBwp"] = x.get_is_initial_bwp();
        j["subCarrierSpacing"] = x.get_sub_carrier_spacing();
        j["cyclicPrefix"] = x.get_cyclic_prefix();
        j["startRB"] = x.get_start_rb();
        j["numberOfRBs"] = x.get_number_of_r_bs();
    }

    inline void from_json(const json & j, OBwp& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<OBwpProperties>());
    }

    inline void to_json(json & j, const OBwp & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, OCellDtxdrxConfigProperties& x) {
        x.set_on_duration_timer(j.at("onDurationTimer").get<ItemsElement>());
        x.set_cycle_start_offset(j.at("cycleStartOffset").get<ItemsElement>());
        x.set_slot_offset(j.at("slotOffset").get<GnbCuUpId>());
        x.set_config_type(j.at("configType").get<AdministrativeState>());
        x.set_activation_status(j.at("activationStatus").get<AdministrativeState>());
        x.set_l1_activation(j.at("l1Activation").get<AdministrativeState>());
    }

    inline void to_json(json & j, const OCellDtxdrxConfigProperties & x) {
        j = json::object();
        j["onDurationTimer"] = x.get_on_duration_timer();
        j["cycleStartOffset"] = x.get_cycle_start_offset();
        j["slotOffset"] = x.get_slot_offset();
        j["configType"] = x.get_config_type();
        j["activationStatus"] = x.get_activation_status();
        j["l1Activation"] = x.get_l1_activation();
    }

    inline void from_json(const json & j, OCellDtxdrxConfig& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<OCellDtxdrxConfigProperties>());
    }

    inline void to_json(json & j, const OCellDtxdrxConfig & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, OCesManagementFunctionProperties& x) {
        x.set_ces_switch(j.at("cesSwitch").get<EutraCellIdentity>());
        x.set_energy_saving_state(j.at("energySavingState").get<AdministrativeState>());
        x.set_energy_saving_control(j.at("energySavingControl").get<AdministrativeState>());
    }

    inline void to_json(json & j, const OCesManagementFunctionProperties & x) {
        j = json::object();
        j["cesSwitch"] = x.get_ces_switch();
        j["energySavingState"] = x.get_energy_saving_state();
        j["energySavingControl"] = x.get_energy_saving_control();
    }

    inline void from_json(const json & j, OCesManagementFunction& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<OCesManagementFunctionProperties>());
    }

    inline void to_json(json & j, const OCesManagementFunction & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, OGnbCuCpFunction& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<std::map<std::string, ItemsElement>>());
    }

    inline void to_json(json & j, const OGnbCuCpFunction & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, ONesPolicyProperties& x) {
        x.set_policy_type(j.at("policyType").get<AdministrativeState>());
        x.set_antenna_mask_name(j.at("antennaMaskName").get<EutraCellIdentity>());
        x.set_antenna_mask(j.at("antennaMask").get<EutraCellIdentity>());
        x.set_sleep_mode(j.at("sleepMode").get<AdministrativeState>());
        x.set_data_dir(j.at("dataDir").get<AdministrativeState>());
        x.set_symbol_mask(j.at("symbolMask").get<GnbCuUpId>());
        x.set_slot_mask(j.at("slotMask").get<EutraCellIdentity>());
        x.set_valid_duration(j.at("validDuration").get<EutraCellIdentity>());
        x.set_es_objective(j.at("esObjective").get<ItemsElement>());
        x.set_perf_objective_list(j.at("perfObjectiveList").get<ItemsElement>());
    }

    inline void to_json(json & j, const ONesPolicyProperties & x) {
        j = json::object();
        j["policyType"] = x.get_policy_type();
        j["antennaMaskName"] = x.get_antenna_mask_name();
        j["antennaMask"] = x.get_antenna_mask();
        j["sleepMode"] = x.get_sleep_mode();
        j["dataDir"] = x.get_data_dir();
        j["symbolMask"] = x.get_symbol_mask();
        j["slotMask"] = x.get_slot_mask();
        j["validDuration"] = x.get_valid_duration();
        j["esObjective"] = x.get_es_objective();
        j["perfObjectiveList"] = x.get_perf_objective_list();
    }

    inline void from_json(const json & j, ONesPolicy& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ONesPolicyProperties>());
    }

    inline void to_json(json & j, const ONesPolicy & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, ONrCellCuProperties& x) {
        x.set_cell_local_id(j.at("cellLocalId").get<EutraCellIdentity>());
        x.set_plmn_info_list(j.at("plmnInfoList").get<ItemsElement>());
    }

    inline void to_json(json & j, const ONrCellCuProperties & x) {
        j = json::object();
        j["cellLocalId"] = x.get_cell_local_id();
        j["plmnInfoList"] = x.get_plmn_info_list();
    }

    inline void from_json(const json & j, ONrCellCu& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ONrCellCuProperties>());
    }

    inline void to_json(json & j, const ONrCellCu & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, ONrCellDuProperties& x) {
        x.set_cell_local_id(j.at("cellLocalId").get<EutraCellIdentity>());
        x.set_operational_state(j.at("operationalState").get<ItemsElement>());
        x.set_administrative_state(j.at("administrativeState").get<ItemsElement>());
        x.set_cell_state(j.at("cellState").get<ItemsElement>());
        x.set_plmn_info_list(j.at("plmnInfoList").get<ItemsElement>());
        x.set_nr_pci(j.at("nrPci").get<ItemsElement>());
        x.set_nr_tac(j.at("nrTac").get<ItemsElement>());
        x.set_arfcn_dl(j.at("arfcnDL").get<EutraCellIdentity>());
        x.set_arfcn_ul(j.at("arfcnUL").get<EutraCellIdentity>());
        x.set_arfcn_sul(j.at("arfcnSUL").get<EutraCellIdentity>());
        x.set_b_s_channel_bw_dl(j.at("bSChannelBwDL").get<EutraCellIdentity>());
        x.set_ssb_frequency(j.at("ssbFrequency").get<GnbCuUpId>());
        x.set_ssb_periodicity(j.at("ssbPeriodicity").get<ItemsElement>());
        x.set_ssb_sub_carrier_spacing(j.at("ssbSubCarrierSpacing").get<ItemsElement>());
        x.set_ssb_offset(j.at("ssbOffset").get<GnbCuUpId>());
        x.set_ssb_duration(j.at("ssbDuration").get<ItemsElement>());
        x.set_b_s_channel_bw_ul(j.at("bSChannelBwUL").get<EutraCellIdentity>());
        x.set_b_s_channel_bw_sul(j.at("bSChannelBwSUL").get<EutraCellIdentity>());
        x.set_bwp_list(j.at("bwpList").get<GEnbIdList>());
        x.set_partition_list(j.at("partitionList").get<ItemsElement>());
    }

    inline void to_json(json & j, const ONrCellDuProperties & x) {
        j = json::object();
        j["cellLocalId"] = x.get_cell_local_id();
        j["operationalState"] = x.get_operational_state();
        j["administrativeState"] = x.get_administrative_state();
        j["cellState"] = x.get_cell_state();
        j["plmnInfoList"] = x.get_plmn_info_list();
        j["nrPci"] = x.get_nr_pci();
        j["nrTac"] = x.get_nr_tac();
        j["arfcnDL"] = x.get_arfcn_dl();
        j["arfcnUL"] = x.get_arfcn_ul();
        j["arfcnSUL"] = x.get_arfcn_sul();
        j["bSChannelBwDL"] = x.get_b_s_channel_bw_dl();
        j["ssbFrequency"] = x.get_ssb_frequency();
        j["ssbPeriodicity"] = x.get_ssb_periodicity();
        j["ssbSubCarrierSpacing"] = x.get_ssb_sub_carrier_spacing();
        j["ssbOffset"] = x.get_ssb_offset();
        j["ssbDuration"] = x.get_ssb_duration();
        j["bSChannelBwUL"] = x.get_b_s_channel_bw_ul();
        j["bSChannelBwSUL"] = x.get_b_s_channel_bw_sul();
        j["bwpList"] = x.get_bwp_list();
        j["partitionList"] = x.get_partition_list();
    }

    inline void from_json(const json & j, ONrCellDu& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ONrCellDuProperties>());
    }

    inline void to_json(json & j, const ONrCellDu & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, OPrbBlankingPolicyProperties& x) {
        x.set_policy_category(j.at("policyCategory").get<AdministrativeState>());
        x.set_link_dir(j.at("linkDir").get<AdministrativeState>());
        x.set_start_time(j.at("startTime").get<EutraCellIdentity>());
        x.set_end_time(j.at("endTime").get<EutraCellIdentity>());
        x.set_prb_blanking_configuration_list(j.at("prbBlankingConfigurationList").get<ItemsElement>());
        x.set_prb_blanking_obj(j.at("prbBlankingObj").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const OPrbBlankingPolicyProperties & x) {
        j = json::object();
        j["policyCategory"] = x.get_policy_category();
        j["linkDir"] = x.get_link_dir();
        j["startTime"] = x.get_start_time();
        j["endTime"] = x.get_end_time();
        j["prbBlankingConfigurationList"] = x.get_prb_blanking_configuration_list();
        j["prbBlankingObj"] = x.get_prb_blanking_obj();
    }

    inline void from_json(const json & j, OPrbBlankingPolicy& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<OPrbBlankingPolicyProperties>());
    }

    inline void to_json(json & j, const OPrbBlankingPolicy & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, ORrmPolicyRatioProperties& x) {
        x.set_resource_type(j.at("resourceType").get<ItemsElement>());
        x.set_r_rm_policy_member_list(j.at("rRMPolicyMemberList").get<ItemsElement>());
        x.set_r_rm_policy_max_ratio(j.at("rRMPolicyMaxRatio").get<EutraCellIdentity>());
        x.set_r_rm_policy_min_ratio(j.at("rRMPolicyMinRatio").get<EutraCellIdentity>());
        x.set_r_rm_policy_dedicated_ratio(j.at("rRMPolicyDedicatedRatio").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const ORrmPolicyRatioProperties & x) {
        j = json::object();
        j["resourceType"] = x.get_resource_type();
        j["rRMPolicyMemberList"] = x.get_r_rm_policy_member_list();
        j["rRMPolicyMaxRatio"] = x.get_r_rm_policy_max_ratio();
        j["rRMPolicyMinRatio"] = x.get_r_rm_policy_min_ratio();
        j["rRMPolicyDedicatedRatio"] = x.get_r_rm_policy_dedicated_ratio();
    }

    inline void from_json(const json & j, ORrmPolicyRatio& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ORrmPolicyRatioProperties>());
    }

    inline void to_json(json & j, const ORrmPolicyRatio & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, ORuInfoProperties& x) {
        x.set_oru_user_plane_configuration(j.at("oruUserPlaneConfiguration").get<ItemsElement>());
        x.set_oru_capabilities(j.at("oruCapabilities").get<ItemsElement>());
    }

    inline void to_json(json & j, const ORuInfoProperties & x) {
        j = json::object();
        j["oruUserPlaneConfiguration"] = x.get_oru_user_plane_configuration();
        j["oruCapabilities"] = x.get_oru_capabilities();
    }

    inline void from_json(const json & j, ORuInfo& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ORuInfoProperties>());
    }

    inline void to_json(json & j, const ORuInfo & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, OnDurationTimer& x) {
        x.set_one_of(j.at("oneOf").get<std::vector<GnbCuUpId>>());
    }

    inline void to_json(json & j, const OnDurationTimer & x) {
        j = json::object();
        j["oneOf"] = x.get_one_of();
    }

    inline void from_json(const json & j, OruCapabilitiesProperties& x) {
        x.set_energy_saving_capability_common_info(j.at("energySavingCapabilityCommonInfo").get<ItemsElement>());
        x.set_asm_capability_info(j.at("asmCapabilityInfo").get<ItemsElement>());
        x.set_trx_control_capability_info(j.at("trxControlCapabilityInfo").get<ItemsElement>());
    }

    inline void to_json(json & j, const OruCapabilitiesProperties & x) {
        j = json::object();
        j["energySavingCapabilityCommonInfo"] = x.get_energy_saving_capability_common_info();
        j["asmCapabilityInfo"] = x.get_asm_capability_info();
        j["trxControlCapabilityInfo"] = x.get_trx_control_capability_info();
    }

    inline void from_json(const json & j, OruCapabilities& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<OruCapabilitiesProperties>());
    }

    inline void to_json(json & j, const OruCapabilities & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, OruUserPlaneConfigurationProperties& x) {
        x.set_tx_array_list(j.at("txArrayList").get<ItemsElement>());
        x.set_rx_array_list(j.at("rxArrayList").get<ItemsElement>());
    }

    inline void to_json(json & j, const OruUserPlaneConfigurationProperties & x) {
        j = json::object();
        j["txArrayList"] = x.get_tx_array_list();
        j["rxArrayList"] = x.get_rx_array_list();
    }

    inline void from_json(const json & j, OruUserPlaneConfiguration& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<OruUserPlaneConfigurationProperties>());
    }

    inline void to_json(json & j, const OruUserPlaneConfiguration & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, PurpleProperties& x) {
        x.set_snssai(j.at("snssai").get<ItemsElement>());
        x.set_plmn_id(j.at("plmnId").get<ItemsElement>());
        x.set_the_5__qi_list(j.at("5qiList").get<ItemsElement>());
    }

    inline void to_json(json & j, const PurpleProperties & x) {
        j = json::object();
        j["snssai"] = x.get_snssai();
        j["plmnId"] = x.get_plmn_id();
        j["5qiList"] = x.get_the_5__qi_list();
    }

    inline void from_json(const json & j, PartitionFlowListItems& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<PurpleProperties>());
    }

    inline void to_json(json & j, const PartitionFlowListItems & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, PartitionFlowList& x) {
        x.set_type(j.at("type").get<The5QiListType>());
        x.set_items(j.at("items").get<PartitionFlowListItems>());
    }

    inline void to_json(json & j, const PartitionFlowList & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["items"] = x.get_items();
    }

    inline void from_json(const json & j, FluffyProperties& x) {
        x.set_p_offset_to_point_a(j.at("pOffsetToPointA").get<EutraCellIdentity>());
        x.set_p_number_of_r_bs(j.at("pNumberOfRBs").get<EutraCellIdentity>());
        x.set_partition_flow_list(j.at("partitionFlowList").get<ItemsElement>());
    }

    inline void to_json(json & j, const FluffyProperties & x) {
        j = json::object();
        j["pOffsetToPointA"] = x.get_p_offset_to_point_a();
        j["pNumberOfRBs"] = x.get_p_number_of_r_bs();
        j["partitionFlowList"] = x.get_partition_flow_list();
    }

    inline void from_json(const json & j, PartitionListItems& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<FluffyProperties>());
    }

    inline void to_json(json & j, const PartitionListItems & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, PartitionList& x) {
        x.set_type(j.at("type").get<The5QiListType>());
        x.set_items(j.at("items").get<PartitionListItems>());
    }

    inline void to_json(json & j, const PartitionList & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["items"] = x.get_items();
    }

    inline void from_json(const json & j, PerfObjectiveProperties& x) {
        x.set_plmn_info_list(j.at("plmnInfoList").get<ItemsElement>());
        x.set_five_qi_value(j.at("fiveQIValue").get<GnbCuUpId>());
        x.set_max_ngbr_flow_br(j.at("maxNgbrFlowBr").get<EutraCellIdentity>());
        x.set_flow_br_avg_window(j.at("flowBrAvgWindow").get<GnbCuUpId>());
        x.set_max_pd(j.at("maxPd").get<GnbCuUpId>());
        x.set_target_pd(j.at("targetPd").get<GnbCuUpId>());
    }

    inline void to_json(json & j, const PerfObjectiveProperties & x) {
        j = json::object();
        j["plmnInfoList"] = x.get_plmn_info_list();
        j["fiveQIValue"] = x.get_five_qi_value();
        j["maxNgbrFlowBr"] = x.get_max_ngbr_flow_br();
        j["flowBrAvgWindow"] = x.get_flow_br_avg_window();
        j["maxPd"] = x.get_max_pd();
        j["targetPd"] = x.get_target_pd();
    }

    inline void from_json(const json & j, PerfObjective& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<PerfObjectiveProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const PerfObjective & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, NumberOfRBs& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_minimum(j.at("minimum").get<int64_t>());
    }

    inline void to_json(json & j, const NumberOfRBs & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["minimum"] = x.get_minimum();
    }

    inline void from_json(const json & j, TentacledProperties& x) {
        x.set_start_rb(j.at("startRB").get<NumberOfRBs>());
        x.set_number_of_r_bs(j.at("numberOfRBs").get<NumberOfRBs>());
        x.set_symbol_mask(j.at("symbolMask").get<GnbCuUpId>());
        x.set_slot_mask(j.at("slotMask").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const TentacledProperties & x) {
        j = json::object();
        j["startRB"] = x.get_start_rb();
        j["numberOfRBs"] = x.get_number_of_r_bs();
        j["symbolMask"] = x.get_symbol_mask();
        j["slotMask"] = x.get_slot_mask();
    }

    inline void from_json(const json & j, PrbBlankingConfigurationListItems& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<TentacledProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const PrbBlankingConfigurationListItems & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, PrbBlankingConfigurationList& x) {
        x.set_type(j.at("type").get<The5QiListType>());
        x.set_items(j.at("items").get<PrbBlankingConfigurationListItems>());
    }

    inline void to_json(json & j, const PrbBlankingConfigurationList & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["items"] = x.get_items();
    }

    inline void from_json(const json & j, QueryServiceProperties& x) {
        x.set_list_of_supported_query_styles(j.at("listOfSupportedQueryStyles").get<ItemsElement>());
    }

    inline void to_json(json & j, const QueryServiceProperties & x) {
        j = json::object();
        j["listOfSupportedQueryStyles"] = x.get_list_of_supported_query_styles();
    }

    inline void from_json(const json & j, QueryService& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<QueryServiceProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const QueryService & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, QueryStyleProperties& x) {
        x.set_query_service_style_type(j.at("queryServiceStyleType").get<EutraCellIdentity>());
        x.set_query_service_style_name(j.at("queryServiceStyleName").get<EutraCellIdentity>());
        x.set_query_service_header_format_type(j.at("queryServiceHeaderFormatType").get<EutraCellIdentity>());
        x.set_query_service_definition_format_type(j.at("queryServiceDefinitionFormatType").get<EutraCellIdentity>());
        x.set_query_service_outcome_format_type(j.at("queryServiceOutcomeFormatType").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const QueryStyleProperties & x) {
        j = json::object();
        j["queryServiceStyleType"] = x.get_query_service_style_type();
        j["queryServiceStyleName"] = x.get_query_service_style_name();
        j["queryServiceHeaderFormatType"] = x.get_query_service_header_format_type();
        j["queryServiceDefinitionFormatType"] = x.get_query_service_definition_format_type();
        j["queryServiceOutcomeFormatType"] = x.get_query_service_outcome_format_type();
    }

    inline void from_json(const json & j, QueryStyle& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<QueryStyleProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const QueryStyle & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RPolarizationItemProperties& x) {
        x.set_r_polarization_index(j.at("rPolarizationIndex").get<GnbCuUpId>());
        x.set_r_polarization_type(j.at("rPolarizationType").get<AdministrativeState>());
    }

    inline void to_json(json & j, const RPolarizationItemProperties & x) {
        j = json::object();
        j["rPolarizationIndex"] = x.get_r_polarization_index();
        j["rPolarizationType"] = x.get_r_polarization_type();
    }

    inline void from_json(const json & j, RPolarizationItem& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RPolarizationItemProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RPolarizationItem & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RanConfigurationStructureProperties& x) {
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_list_of_supported_attributes(j.at("listOfSupportedAttributes").get<ItemsElement>());
    }

    inline void to_json(json & j, const RanConfigurationStructureProperties & x) {
        j = json::object();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["listOfSupportedAttributes"] = x.get_list_of_supported_attributes();
    }

    inline void from_json(const json & j, RanConfigurationStructure& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RanConfigurationStructureProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RanConfigurationStructure & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RanConfigurationStructureForAdfProperties& x) {
        x.set_report_type(j.at("reportType").get<ChangeType>());
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_list_of_attributes(j.at("listOfAttributes").get<GEnbIdList>());
    }

    inline void to_json(json & j, const RanConfigurationStructureForAdfProperties & x) {
        j = json::object();
        j["reportType"] = x.get_report_type();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["listOfAttributes"] = x.get_list_of_attributes();
    }

    inline void from_json(const json & j, RanConfigurationStructureForAdf& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RanConfigurationStructureForAdfProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RanConfigurationStructureForAdf & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, The5_QiList& x) {
        x.set_type(j.at("type").get<The5QiListType>());
        x.set_items(j.at("items").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const The5_QiList & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["items"] = x.get_items();
    }

    inline void from_json(const json & j, RanConfigurationStructureForEventTriggerProperties& x) {
        x.set_ran_configuration_structure_name(j.at("ranConfigurationStructureName").get<EutraCellIdentity>());
        x.set_list_of_attributes(j.at("listOfAttributes").get<The5_QiList>());
    }

    inline void to_json(json & j, const RanConfigurationStructureForEventTriggerProperties & x) {
        j = json::object();
        j["ranConfigurationStructureName"] = x.get_ran_configuration_structure_name();
        j["listOfAttributes"] = x.get_list_of_attributes();
    }

    inline void from_json(const json & j, RanConfigurationStructureForEventTrigger& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RanConfigurationStructureForEventTriggerProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RanConfigurationStructureForEventTrigger & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RanFunctionDefinitionProperties& x) {
        x.set_ran_function_name(j.at("ranFunctionName").get<ItemsElement>());
        x.set_list_of_supported_node_level_configuration_structures(j.at("listOfSupportedNodeLevelConfigurationStructures").get<ItemsElement>());
        x.set_list_of_cells_for_ran_function_definition(j.at("listOfCellsForRANFunctionDefinition").get<ItemsElement>());
    }

    inline void to_json(json & j, const RanFunctionDefinitionProperties & x) {
        j = json::object();
        j["ranFunctionName"] = x.get_ran_function_name();
        j["listOfSupportedNodeLevelConfigurationStructures"] = x.get_list_of_supported_node_level_configuration_structures();
        j["listOfCellsForRANFunctionDefinition"] = x.get_list_of_cells_for_ran_function_definition();
    }

    inline void from_json(const json & j, RanFunctionDefinition& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RanFunctionDefinitionProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RanFunctionDefinition & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RanFunctionNameProperties& x) {
        x.set_ran_function_short_name(j.at("ranFunctionShortName").get<EutraCellIdentity>());
        x.set_ran_function_service_model_oid(j.at("ranFunctionServiceModelOID").get<EutraCellIdentity>());
        x.set_ran_function_description(j.at("ranFunctionDescription").get<EutraCellIdentity>());
        x.set_ran_function_instance(j.at("ranFunctionInstance").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const RanFunctionNameProperties & x) {
        j = json::object();
        j["ranFunctionShortName"] = x.get_ran_function_short_name();
        j["ranFunctionServiceModelOID"] = x.get_ran_function_service_model_oid();
        j["ranFunctionDescription"] = x.get_ran_function_description();
        j["ranFunctionInstance"] = x.get_ran_function_instance();
    }

    inline void from_json(const json & j, RanFunctionName& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RanFunctionNameProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RanFunctionName & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ReportServiceProperties& x) {
        x.set_list_of_supported_report_styles(j.at("listOfSupportedReportStyles").get<ItemsElement>());
    }

    inline void to_json(json & j, const ReportServiceProperties & x) {
        j = json::object();
        j["listOfSupportedReportStyles"] = x.get_list_of_supported_report_styles();
    }

    inline void from_json(const json & j, ReportService& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ReportServiceProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ReportService & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ReportStyleProperties& x) {
        x.set_report_service_style_type(j.at("reportServiceStyleType").get<EutraCellIdentity>());
        x.set_report_service_style_name(j.at("reportServiceStyleName").get<EutraCellIdentity>());
        x.set_list_of_supported_event_trigger_styles_for_report_style(j.at("listOfSupportedEventTriggerStylesForReportStyle").get<GEnbIdList>());
        x.set_report_service_action_definition_format_type(j.at("reportServiceActionDefinitionFormatType").get<EutraCellIdentity>());
        x.set_report_service_indication_header_format_type(j.at("reportServiceIndicationHeaderFormatType").get<EutraCellIdentity>());
        x.set_report_service_indication_message_format_type(j.at("reportServiceIndicationMessageFormatType").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const ReportStyleProperties & x) {
        j = json::object();
        j["reportServiceStyleType"] = x.get_report_service_style_type();
        j["reportServiceStyleName"] = x.get_report_service_style_name();
        j["listOfSupportedEventTriggerStylesForReportStyle"] = x.get_list_of_supported_event_trigger_styles_for_report_style();
        j["reportServiceActionDefinitionFormatType"] = x.get_report_service_action_definition_format_type();
        j["reportServiceIndicationHeaderFormatType"] = x.get_report_service_indication_header_format_type();
        j["reportServiceIndicationMessageFormatType"] = x.get_report_service_indication_message_format_type();
    }

    inline void from_json(const json & j, ReportStyle& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ReportStyleProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ReportStyle & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicActionDefinitionProperties& x) {
        x.set_ric_style_type(j.at("ricStyleType").get<EutraCellIdentity>());
        x.set_action_definition_format(j.at("actionDefinitionFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicActionDefinitionProperties & x) {
        j = json::object();
        j["ricStyleType"] = x.get_ric_style_type();
        j["actionDefinitionFormat"] = x.get_action_definition_format();
    }

    inline void from_json(const json & j, RicActionDefinition& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicActionDefinitionProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicActionDefinition & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicControlHeaderProperties& x) {
        x.set_control_header_format(j.at("controlHeaderFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicControlHeaderProperties & x) {
        j = json::object();
        j["controlHeaderFormat"] = x.get_control_header_format();
    }

    inline void from_json(const json & j, RicControlHeader& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicControlHeaderProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicControlHeader & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicControlMessageProperties& x) {
        x.set_control_message_format(j.at("controlMessageFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicControlMessageProperties & x) {
        j = json::object();
        j["controlMessageFormat"] = x.get_control_message_format();
    }

    inline void from_json(const json & j, RicControlMessage& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicControlMessageProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicControlMessage & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicControlOutcomeProperties& x) {
        x.set_control_outcome_format(j.at("controlOutcomeFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicControlOutcomeProperties & x) {
        j = json::object();
        j["controlOutcomeFormat"] = x.get_control_outcome_format();
    }

    inline void from_json(const json & j, RicControlOutcome& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicControlOutcomeProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicControlOutcome & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicEventTriggerDefinitionProperties& x) {
        x.set_event_trigger_definition_format(j.at("eventTriggerDefinitionFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicEventTriggerDefinitionProperties & x) {
        j = json::object();
        j["eventTriggerDefinitionFormat"] = x.get_event_trigger_definition_format();
    }

    inline void from_json(const json & j, RicEventTriggerDefinition& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicEventTriggerDefinitionProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicEventTriggerDefinition & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicIndicationHeaderProperties& x) {
        x.set_indication_header_format(j.at("indicationHeaderFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicIndicationHeaderProperties & x) {
        j = json::object();
        j["indicationHeaderFormat"] = x.get_indication_header_format();
    }

    inline void from_json(const json & j, RicIndicationHeader& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicIndicationHeaderProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicIndicationHeader & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicIndicationMessageProperties& x) {
        x.set_indication_message_format(j.at("indicationMessageFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicIndicationMessageProperties & x) {
        j = json::object();
        j["indicationMessageFormat"] = x.get_indication_message_format();
    }

    inline void from_json(const json & j, RicIndicationMessage& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicIndicationMessageProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicIndicationMessage & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicQueryDefinitionProperties& x) {
        x.set_query_definition_format(j.at("queryDefinitionFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicQueryDefinitionProperties & x) {
        j = json::object();
        j["queryDefinitionFormat"] = x.get_query_definition_format();
    }

    inline void from_json(const json & j, RicQueryDefinition& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicQueryDefinitionProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicQueryDefinition & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicQueryHeaderProperties& x) {
        x.set_query_header_format(j.at("queryHeaderFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicQueryHeaderProperties & x) {
        j = json::object();
        j["queryHeaderFormat"] = x.get_query_header_format();
    }

    inline void from_json(const json & j, RicQueryHeader& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicQueryHeaderProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicQueryHeader & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicQueryOutcomeProperties& x) {
        x.set_query_outcome_format(j.at("queryOutcomeFormat").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicQueryOutcomeProperties & x) {
        j = json::object();
        j["queryOutcomeFormat"] = x.get_query_outcome_format();
    }

    inline void from_json(const json & j, RicQueryOutcome& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicQueryOutcomeProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RicQueryOutcome & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, RicServicesProperties& x) {
        x.set_event_trigger(j.at("eventTrigger").get<ItemsElement>());
        x.set_report_service(j.at("reportService").get<ItemsElement>());
        x.set_insert_service(j.at("insertService").get<ItemsElement>());
        x.set_control_service(j.at("controlService").get<ItemsElement>());
        x.set_policy_service(j.at("policyService").get<ItemsElement>());
        x.set_query_service(j.at("queryService").get<ItemsElement>());
    }

    inline void to_json(json & j, const RicServicesProperties & x) {
        j = json::object();
        j["eventTrigger"] = x.get_event_trigger();
        j["reportService"] = x.get_report_service();
        j["insertService"] = x.get_insert_service();
        j["controlService"] = x.get_control_service();
        j["policyService"] = x.get_policy_service();
        j["queryService"] = x.get_query_service();
    }

    inline void from_json(const json & j, RicServices& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RicServicesProperties>());
    }

    inline void to_json(json & j, const RicServices & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, RGainCorrectionRangeProperties& x) {
        x.set_r_max(j.at("rMax").get<EutraCellIdentity>());
        x.set_r_min(j.at("rMin").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const RGainCorrectionRangeProperties & x) {
        j = json::object();
        j["rMax"] = x.get_r_max();
        j["rMin"] = x.get_r_min();
    }

    inline void from_json(const json & j, RGainCorrectionRange& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RGainCorrectionRangeProperties>());
    }

    inline void to_json(json & j, const RGainCorrectionRange & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, RLeftmostBottomArrayElementPositionProperties& x) {
        x.set_r_x_axis(j.at("rXAxis").get<EutraCellIdentity>());
        x.set_r_y_axis(j.at("rYAxis").get<EutraCellIdentity>());
        x.set_r_z_axis(j.at("rZAxis").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const RLeftmostBottomArrayElementPositionProperties & x) {
        j = json::object();
        j["rXAxis"] = x.get_r_x_axis();
        j["rYAxis"] = x.get_r_y_axis();
        j["rZAxis"] = x.get_r_z_axis();
    }

    inline void from_json(const json & j, RLeftmostBottomArrayElementPosition& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RLeftmostBottomArrayElementPositionProperties>());
    }

    inline void to_json(json & j, const RLeftmostBottomArrayElementPosition & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, RNormalVectorDirectionProperties& x) {
        x.set_r_azimuth_angle(j.at("rAzimuthAngle").get<EutraCellIdentity>());
        x.set_r_zenith_angle(j.at("rZenithAngle").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const RNormalVectorDirectionProperties & x) {
        j = json::object();
        j["rAzimuthAngle"] = x.get_r_azimuth_angle();
        j["rZenithAngle"] = x.get_r_zenith_angle();
    }

    inline void from_json(const json & j, RNormalVectorDirection& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RNormalVectorDirectionProperties>());
    }

    inline void to_json(json & j, const RNormalVectorDirection & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, RxArrayItemProperties& x) {
        x.set_r_name(j.at("rName").get<EutraCellIdentity>());
        x.set_r_number_of_rows(j.at("rNumberOfRows").get<GnbCuUpId>());
        x.set_r_number_of_columns(j.at("rNumberOfColumns").get<GnbCuUpId>());
        x.set_r_number_of_array_layers(j.at("rNumberOfArrayLayers").get<GnbCuUpId>());
        x.set_r_horizontal_spacing(j.at("rHorizontalSpacing").get<EutraCellIdentity>());
        x.set_r_vertical_spacing(j.at("rVerticalSpacing").get<EutraCellIdentity>());
        x.set_r_normal_vector_direction(j.at("rNormalVectorDirection").get<RNormalVectorDirection>());
        x.set_r_leftmost_bottom_array_element_position(j.at("rLeftmostBottomArrayElementPosition").get<RLeftmostBottomArrayElementPosition>());
        x.set_r_polarization_list(j.at("rPolarizationList").get<GEnbIdList>());
        x.set_r_band_number(j.at("rBandNumber").get<GnbCuUpId>());
        x.set_r_gain_correction_range(j.at("rGainCorrectionRange").get<RGainCorrectionRange>());
    }

    inline void to_json(json & j, const RxArrayItemProperties & x) {
        j = json::object();
        j["rName"] = x.get_r_name();
        j["rNumberOfRows"] = x.get_r_number_of_rows();
        j["rNumberOfColumns"] = x.get_r_number_of_columns();
        j["rNumberOfArrayLayers"] = x.get_r_number_of_array_layers();
        j["rHorizontalSpacing"] = x.get_r_horizontal_spacing();
        j["rVerticalSpacing"] = x.get_r_vertical_spacing();
        j["rNormalVectorDirection"] = x.get_r_normal_vector_direction();
        j["rLeftmostBottomArrayElementPosition"] = x.get_r_leftmost_bottom_array_element_position();
        j["rPolarizationList"] = x.get_r_polarization_list();
        j["rBandNumber"] = x.get_r_band_number();
        j["rGainCorrectionRange"] = x.get_r_gain_correction_range();
    }

    inline void from_json(const json & j, RxArrayItem& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<RxArrayItemProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const RxArrayItem & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, SleepModeProperties& x) {
        x.set_sleep_mode_type(j.at("sleepModeType").get<AdministrativeState>());
        x.set_wakeup_duration(j.at("wakeupDuration").get<EutraCellIdentity>());
        x.set_wakeup_duration_guaranteed(j.at("wakeupDurationGuaranteed").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const SleepModeProperties & x) {
        j = json::object();
        j["sleepModeType"] = x.get_sleep_mode_type();
        j["wakeupDuration"] = x.get_wakeup_duration();
        j["wakeupDurationGuaranteed"] = x.get_wakeup_duration_guaranteed();
    }

    inline void from_json(const json & j, SleepMode& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<SleepModeProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const SleepMode & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, SnssaiProperties& x) {
        x.set_sst(j.at("sst").get<ItemsElement>());
        x.set_sd(j.at("sd").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const SnssaiProperties & x) {
        j = json::object();
        j["sst"] = x.get_sst();
        j["sd"] = x.get_sd();
    }

    inline void from_json(const json & j, Snssai& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<SnssaiProperties>());
    }

    inline void to_json(json & j, const Snssai & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, SsbDuration& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_ssb_duration_enum(j.at("enum").get<std::vector<int64_t>>());
    }

    inline void to_json(json & j, const SsbDuration & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["enum"] = x.get_ssb_duration_enum();
    }

    inline void from_json(const json & j, Sst& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_maximum(j.at("maximum").get<int64_t>());
    }

    inline void to_json(json & j, const Sst & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["maximum"] = x.get_maximum();
    }

    inline void from_json(const json & j, SupportedTrxControlMaskProperties& x) {
        x.set_mask_name(j.at("maskName").get<EutraCellIdentity>());
        x.set_antenna_mask(j.at("antennaMask").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const SupportedTrxControlMaskProperties & x) {
        j = json::object();
        j["maskName"] = x.get_mask_name();
        j["antennaMask"] = x.get_antenna_mask();
    }

    inline void from_json(const json & j, SupportedTrxControlMask& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<SupportedTrxControlMaskProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const SupportedTrxControlMask & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, TPolarizationItemProperties& x) {
        x.set_t_polarization_index(j.at("tPolarizationIndex").get<GnbCuUpId>());
        x.set_t_polarization_type(j.at("tPolarizationType").get<AdministrativeState>());
    }

    inline void to_json(json & j, const TPolarizationItemProperties & x) {
        j = json::object();
        j["tPolarizationIndex"] = x.get_t_polarization_index();
        j["tPolarizationType"] = x.get_t_polarization_type();
    }

    inline void from_json(const json & j, TPolarizationItem& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<TPolarizationItemProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const TPolarizationItem & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, TLeftmostBottomArrayElementPositionProperties& x) {
        x.set_t_x_axis(j.at("tXAxis").get<EutraCellIdentity>());
        x.set_t_y_axis(j.at("tYAxis").get<EutraCellIdentity>());
        x.set_t_z_axis(j.at("tZAxis").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const TLeftmostBottomArrayElementPositionProperties & x) {
        j = json::object();
        j["tXAxis"] = x.get_t_x_axis();
        j["tYAxis"] = x.get_t_y_axis();
        j["tZAxis"] = x.get_t_z_axis();
    }

    inline void from_json(const json & j, TLeftmostBottomArrayElementPosition& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<TLeftmostBottomArrayElementPositionProperties>());
    }

    inline void to_json(json & j, const TLeftmostBottomArrayElementPosition & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, TNormalVectorDirectionProperties& x) {
        x.set_t_azimuth_angle(j.at("tAzimuthAngle").get<EutraCellIdentity>());
        x.set_t_zenith_angle(j.at("tZenithAngle").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const TNormalVectorDirectionProperties & x) {
        j = json::object();
        j["tAzimuthAngle"] = x.get_t_azimuth_angle();
        j["tZenithAngle"] = x.get_t_zenith_angle();
    }

    inline void from_json(const json & j, TNormalVectorDirection& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<TNormalVectorDirectionProperties>());
    }

    inline void to_json(json & j, const TNormalVectorDirection & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json & j, TxArrayItemProperties& x) {
        x.set_t_name(j.at("tName").get<EutraCellIdentity>());
        x.set_t_number_of_rows(j.at("tNumberOfRows").get<GnbCuUpId>());
        x.set_t_number_of_columns(j.at("tNumberOfColumns").get<GnbCuUpId>());
        x.set_t_number_of_array_layers(j.at("tNumberOfArrayLayers").get<GnbCuUpId>());
        x.set_t_horizontal_spacing(j.at("tHorizontalSpacing").get<EutraCellIdentity>());
        x.set_t_vertical_spacing(j.at("tVerticalSpacing").get<EutraCellIdentity>());
        x.set_t_normal_vector_direction(j.at("tNormalVectorDirection").get<TNormalVectorDirection>());
        x.set_t_leftmost_bottom_array_element_position(j.at("tLeftmostBottomArrayElementPosition").get<TLeftmostBottomArrayElementPosition>());
        x.set_t_polarization_list(j.at("tPolarizationList").get<GEnbIdList>());
        x.set_t_band_number(j.at("tBandNumber").get<GnbCuUpId>());
        x.set_t_max_gain(j.at("tMaxGain").get<EutraCellIdentity>());
        x.set_t_min_gain(j.at("tMinGain").get<EutraCellIdentity>());
        x.set_t_independent_power_budget(j.at("tIndependentPowerBudget").get<EutraCellIdentity>());
    }

    inline void to_json(json & j, const TxArrayItemProperties & x) {
        j = json::object();
        j["tName"] = x.get_t_name();
        j["tNumberOfRows"] = x.get_t_number_of_rows();
        j["tNumberOfColumns"] = x.get_t_number_of_columns();
        j["tNumberOfArrayLayers"] = x.get_t_number_of_array_layers();
        j["tHorizontalSpacing"] = x.get_t_horizontal_spacing();
        j["tVerticalSpacing"] = x.get_t_vertical_spacing();
        j["tNormalVectorDirection"] = x.get_t_normal_vector_direction();
        j["tLeftmostBottomArrayElementPosition"] = x.get_t_leftmost_bottom_array_element_position();
        j["tPolarizationList"] = x.get_t_polarization_list();
        j["tBandNumber"] = x.get_t_band_number();
        j["tMaxGain"] = x.get_t_max_gain();
        j["tMinGain"] = x.get_t_min_gain();
        j["tIndependentPowerBudget"] = x.get_t_independent_power_budget();
    }

    inline void from_json(const json & j, TxArrayItem& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<TxArrayItemProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const TxArrayItem & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, ValuesOfAttributesProperties& x) {
        x.set_ran_configuration_structure(j.at("ranConfigurationStructure").get<ItemsElement>());
    }

    inline void to_json(json & j, const ValuesOfAttributesProperties & x) {
        j = json::object();
        j["ranConfigurationStructure"] = x.get_ran_configuration_structure();
    }

    inline void from_json(const json & j, ValuesOfAttributes& x) {
        x.set_type(j.at("type").get<EutraCellIdentityType>());
        x.set_properties(j.at("properties").get<ValuesOfAttributesProperties>());
        x.set_required(j.at("required").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const ValuesOfAttributes & x) {
        j = json::object();
        j["type"] = x.get_type();
        j["properties"] = x.get_properties();
        j["required"] = x.get_required();
    }

    inline void from_json(const json & j, Schemas& x) {
        x.set_gnb_id(j.at("GnbId").get<GnbCuUpId>());
        x.set_gnb_id_length(j.at("GnbIdLength").get<GnbCuUpId>());
        x.set_gnb_name(j.at("GnbName").get<GnbName>());
        x.set_gnb_du_id(j.at("GnbDuId").get<GnbCuUpId>());
        x.set_gnb_cu_up_id(j.at("GnbCuUpId").get<GnbCuUpId>());
        x.set_sst(j.at("Sst").get<Sst>());
        x.set_snssai(j.at("Snssai").get<Snssai>());
        x.set_snssai_list(j.at("SnssaiList").get<GEnbIdList>());
        x.set_mcc(j.at("Mcc").get<GEnbId>());
        x.set_mnc(j.at("Mnc").get<GEnbId>());
        x.set_plmn_id(j.at("PlmnId").get<OGnbCuCpFunction>());
        x.set_plmn_id_list(j.at("PlmnIdList").get<GEnbIdList>());
        x.set_plmn_info(j.at("PlmnInfo").get<OGnbCuCpFunction>());
        x.set_plmn_info_list(j.at("PlmnInfoList").get<GEnbIdList>());
        x.set_g_gnb_id(j.at("GGnbId").get<GEnbId>());
        x.set_g_enb_id(j.at("GEnbId").get<GEnbId>());
        x.set_g_gnb_id_list(j.at("GGnbIdList").get<GEnbIdList>());
        x.set_g_enb_id_list(j.at("GEnbIdList").get<GEnbIdList>());
        x.set_nr_pci(j.at("NrPci").get<GnbCuUpId>());
        x.set_nr_tac(j.at("NrTac").get<GnbCuUpId>());
        x.set_operational_state(j.at("OperationalState").get<AdministrativeState>());
        x.set_administrative_state(j.at("AdministrativeState").get<AdministrativeState>());
        x.set_cell_state(j.at("CellState").get<AdministrativeState>());
        x.set_cyclic_prefix(j.at("CyclicPrefix").get<AdministrativeState>());
        x.set_bwp_context(j.at("BwpContext").get<AdministrativeState>());
        x.set_is_initial_bwp(j.at("IsInitialBwp").get<AdministrativeState>());
        x.set_sub_carrier_spacing(j.at("SubCarrierSpacing").get<SsbDuration>());
        x.set_ssb_periodicity(j.at("SsbPeriodicity").get<SsbDuration>());
        x.set_ssb_duration(j.at("SsbDuration").get<SsbDuration>());
        x.set_ssb_sub_carrier_spacing(j.at("SsbSubCarrierSpacing").get<SsbDuration>());
        x.set_resource_type(j.at("ResourceType").get<AdministrativeState>());
        x.set_rrm_policy_member(j.at("RrmPolicyMember").get<OGnbCuCpFunction>());
        x.set_rrm_policy_member_list(j.at("RrmPolicyMemberList").get<GEnbIdList>());
        x.set_the_5__qi_list(j.at("5QiList").get<The5_QiList>());
        x.set_partition_flow_list(j.at("PartitionFlowList").get<PartitionFlowList>());
        x.set_partition_list(j.at("PartitionList").get<PartitionList>());
        x.set_prb_blanking_configuration_list(j.at("PrbBlankingConfigurationList").get<PrbBlankingConfigurationList>());
        x.set_es_objective(j.at("EsObjective").get<EsObjective>());
        x.set_perf_objective(j.at("PerfObjective").get<PerfObjective>());
        x.set_perf_objective_list(j.at("PerfObjectiveList").get<GEnbIdList>());
        x.set_sleep_mode(j.at("SleepMode").get<SleepMode>());
        x.set_sleep_modes(j.at("SleepModes").get<GEnbIdList>());
        x.set_supported_trx_control_mask(j.at("SupportedTrxControlMask").get<SupportedTrxControlMask>());
        x.set_supported_trx_control_masks(j.at("SupportedTrxControlMasks").get<GEnbIdList>());
        x.set_energy_saving_capability_common_info(j.at("EnergySavingCapabilityCommonInfo").get<EnergySavingCapabilityCommonInfo>());
        x.set_asm_capability_info(j.at("AsmCapabilityInfo").get<CapabilityInfo>());
        x.set_trx_control_capability_info(j.at("TrxControlCapabilityInfo").get<CapabilityInfo>());
        x.set_oru_capabilities(j.at("OruCapabilities").get<OruCapabilities>());
        x.set_on_duration_timer(j.at("OnDurationTimer").get<OnDurationTimer>());
        x.set_cycle_start_offset(j.at("CycleStartOffset").get<CycleStartOffset>());
        x.set_t_polarization_item(j.at("tPolarizationItem").get<TPolarizationItem>());
        x.set_r_polarization_item(j.at("rPolarizationItem").get<RPolarizationItem>());
        x.set_tx_array_item(j.at("TxArrayItem").get<TxArrayItem>());
        x.set_rx_array_item(j.at("RxArrayItem").get<RxArrayItem>());
        x.set_tx_array_list(j.at("TxArrayList").get<GEnbIdList>());
        x.set_rx_array_list(j.at("RxArrayList").get<GEnbIdList>());
        x.set_oru_user_plane_configuration(j.at("OruUserPlaneConfiguration").get<OruUserPlaneConfiguration>());
        x.set_o_gnb_cu_cp_function(j.at("O-GnbCuCpFunction").get<OGnbCuCpFunction>());
        x.set_o_gnb_cu_up_function(j.at("O-GnbCuUpFunction").get<OGnbCuCpFunction>());
        x.set_o_gnb_du_function(j.at("O-GnbDuFunction").get<OGnbCuCpFunction>());
        x.set_o_nr_cell_cu(j.at("O-NrCellCu").get<ONrCellCu>());
        x.set_o_nr_cell_du(j.at("O-NrCellDu").get<ONrCellDu>());
        x.set_o_rrm_policy_ratio(j.at("O-RRMPolicyRatio").get<ORrmPolicyRatio>());
        x.set_o_bwp(j.at("O-Bwp").get<OBwp>());
        x.set_o_ces_management_function(j.at("O-CESManagementFunction").get<OCesManagementFunction>());
        x.set_o_nes_policy(j.at("O-NESPolicy").get<ONesPolicy>());
        x.set_o_prb_blanking_policy(j.at("O-PRBBlankingPolicy").get<OPrbBlankingPolicy>());
        x.set_o_cell_dtxdrx_config(j.at("O-CellDTXDRXConfig").get<OCellDtxdrxConfig>());
        x.set_o_ru_info(j.at("O-RUInfo").get<ORuInfo>());
        x.set_e2_sm_ccc_ran_configuration_structure(j.at("E2SM-CCC-RAN-Configuration-Structure").get<ActionDefinitionFormat>());
        x.set_ric_indication_header(j.at("RIC-Indication-Header").get<RicIndicationHeader>());
        x.set_indication_header_format(j.at("IndicationHeaderFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_indication_header_format1(j.at("E2SM-CCC-IndicationHeaderFormat1").get<E2SmCccIndicationHeaderFormat1>());
        x.set_ric_indication_message(j.at("RIC-Indication-Message").get<RicIndicationMessage>());
        x.set_indication_message_format(j.at("IndicationMessageFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_indication_message_format1(j.at("E2SM-CCC-IndicationMessageFormat1").get<E2SmCccIndicationMessageFormat1>());
        x.set_list_of_configurations_reported(j.at("ListOfConfigurationsReported").get<GEnbIdList>());
        x.set_configuration_structure(j.at("ConfigurationStructure").get<ConfigurationStructure>());
        x.set_values_of_attributes(j.at("ValuesOfAttributes").get<ValuesOfAttributes>());
        x.set_e2_sm_ccc_indication_message_format2(j.at("E2SM-CCC-IndicationMessageFormat2").get<E2SmCccIndicationMessageFormat2>());
        x.set_list_of_cells_reported(j.at("ListOfCellsReported").get<GEnbIdList>());
        x.set_cell_reported(j.at("CellReported").get<CellReported>());
        x.set_cell_global_id(j.at("CellGlobalId").get<CellGlobalId>());
        x.set_nr_cgi(j.at("NR-CGI").get<NrCgi>());
        x.set_nr_cell_identity(j.at("NRCellIdentity").get<GEnbId>());
        x.set_eutra_cgi(j.at("EUTRA-CGI").get<EutraCgi>());
        x.set_eutra_cell_identity(j.at("EUTRACellIdentity").get<EutraCellIdentity>());
        x.set_ric_control_header(j.at("RIC-Control-Header").get<RicControlHeader>());
        x.set_control_header_format(j.at("ControlHeaderFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_control_header_format1(j.at("E2SM-CCC-ControlHeaderFormat1").get<E2SmCccHeaderFormat1>());
        x.set_ric_control_message(j.at("RIC-Control-Message").get<RicControlMessage>());
        x.set_control_message_format(j.at("ControlMessageFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_control_message_format1(j.at("E2SM-CCC-ControlMessageFormat1").get<E2SmCccControlMessageFormat1>());
        x.set_list_of_configuration_structures(j.at("ListOfConfigurationStructures").get<GEnbIdList>());
        x.set_configuration_structure_write(j.at("ConfigurationStructureWrite").get<ConfigurationStructureWrite>());
        x.set_e2_sm_ccc_control_message_format2(j.at("E2SM-CCC-ControlMessageFormat2").get<E2SmCccControlMessageFormat2>());
        x.set_list_of_cells_controlled(j.at("ListOfCellsControlled").get<GEnbIdList>());
        x.set_cell_controlled(j.at("CellControlled").get<CellControlled>());
        x.set_ran_function_definition(j.at("RANFunctionDefinition").get<RanFunctionDefinition>());
        x.set_ran_function_name(j.at("RANFunctionName").get<RanFunctionName>());
        x.set_list_of_supported_ran_configuration_structures(j.at("ListOfSupportedRANConfigurationStructures").get<GEnbIdList>());
        x.set_ran_configuration_structure(j.at("RANConfigurationStructure").get<RanConfigurationStructure>());
        x.set_list_of_supported_attributes(j.at("ListOfSupportedAttributes").get<GEnbIdList>());
        x.set_attribute(j.at("Attribute").get<Attribute>());
        x.set_ric_services(j.at("RICServices").get<RicServices>());
        x.set_event_trigger(j.at("EventTrigger").get<EventTrigger>());
        x.set_list_of_supported_event_trigger_styles(j.at("ListOfSupportedEventTriggerStyles").get<GEnbIdList>());
        x.set_event_trigger_style(j.at("EventTriggerStyle").get<EventTriggerStyle>());
        x.set_report_service(j.at("ReportService").get<ReportService>());
        x.set_list_of_supported_report_styles(j.at("ListOfSupportedReportStyles").get<GEnbIdList>());
        x.set_report_style(j.at("ReportStyle").get<ReportStyle>());
        x.set_event_trigger_style_type(j.at("EventTriggerStyleType").get<EventTriggerStyleType>());
        x.set_insert_service(j.at("InsertService").get<EutraCellIdentity>());
        x.set_control_service(j.at("ControlService").get<ControlService>());
        x.set_list_of_supported_control_styles(j.at("ListOfSupportedControlStyles").get<GEnbIdList>());
        x.set_control_style(j.at("ControlStyle").get<ControlStyle>());
        x.set_policy_service(j.at("PolicyService").get<EutraCellIdentity>());
        x.set_query_service(j.at("QueryService").get<QueryService>());
        x.set_list_of_supported_query_styles(j.at("ListOfSupportedQueryStyles").get<GEnbIdList>());
        x.set_query_style(j.at("QueryStyle").get<QueryStyle>());
        x.set_list_of_cells_for_ran_function_definition(j.at("ListOfCellsForRANFunctionDefinition").get<GEnbIdList>());
        x.set_cell_for_ran_function_definition(j.at("CellForRANFunctionDefinition").get<CellForRanFunctionDefinition>());
        x.set_ric_event_trigger_definition(j.at("RICEventTriggerDefinition").get<RicEventTriggerDefinition>());
        x.set_event_trigger_definition_format(j.at("EventTriggerDefinitionFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_event_trigger_definition_format1(j.at("E2SM-CCC-EventTriggerDefinition-Format1").get<E2SmCccEventTriggerDefinitionFormat1>());
        x.set_list_of_ran_configuration_structures_for_event_trigger(j.at("ListOfRANConfigurationStructuresForEventTrigger").get<GEnbIdList>());
        x.set_ran_configuration_structure_for_event_trigger(j.at("RANConfigurationStructureForEventTrigger").get<RanConfigurationStructureForEventTrigger>());
        x.set_e2_sm_ccc_event_trigger_definition_format2(j.at("E2SM-CCC-EventTriggerDefinition-Format2").get<E2SmCccEventTriggerDefinitionFormat2>());
        x.set_list_of_cell_level_configuration_structures_for_event_trigger(j.at("ListOfCellLevelConfigurationStructuresForEventTrigger").get<GEnbIdList>());
        x.set_cell_level_configuration_structure_for_event_trigger(j.at("CellLevelConfigurationStructureForEventTrigger").get<CellLevelConfigurationStructureForEventTrigger>());
        x.set_e2_sm_ccc_event_trigger_definition_format3(j.at("E2SM-CCC-EventTriggerDefinition-Format3").get<E2SmCccEventTriggerDefinitionFormat3>());
        x.set_ric_action_definition(j.at("RICActionDefinition").get<RicActionDefinition>());
        x.set_action_definition_format(j.at("ActionDefinitionFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_action_definition_format1(j.at("E2SM-CCC-ActionDefinitionFormat1").get<E2SmCccActionDefinitionFormat1>());
        x.set_list_of_ran_configuration_structures_for_adf(j.at("ListOfRANConfigurationStructuresForADF").get<GEnbIdList>());
        x.set_ran_configuration_structure_for_adf(j.at("RANConfigurationStructureForADF").get<RanConfigurationStructureForAdf>());
        x.set_attribute_name(j.at("AttributeName").get<AttributeName>());
        x.set_e2_sm_ccc_action_definition_format2(j.at("E2SM-CCC-ActionDefinitionFormat2").get<E2SmCccActionDefinitionFormat2>());
        x.set_list_of_cell_configurations_to_be_reported_for_adf(j.at("ListOfCellConfigurationsToBeReportedForADF").get<GEnbIdList>());
        x.set_cell_configuration_to_be_reported_for_adf(j.at("CellConfigurationToBeReportedForADF").get<CellConfigurationToBeReportedForAdf>());
        x.set_ric_control_outcome(j.at("RIC-Control-Outcome").get<RicControlOutcome>());
        x.set_control_outcome_format(j.at("ControlOutcomeFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_control_outcome_format1(j.at("E2SM-CCC-ControlOutcomeFormat1").get<E2SmCccControlOutcomeFormat1>());
        x.set_ran_configuration_structures_accepted_list(j.at("RanConfigurationStructuresAcceptedList").get<GEnbIdList>());
        x.set_configuration_structure_accepted(j.at("ConfigurationStructureAccepted").get<ConfigurationStructureAccepted>());
        x.set_ran_configuration_structures_failed_list(j.at("RanConfigurationStructuresFailedList").get<GEnbIdList>());
        x.set_configuration_structure_failed(j.at("ConfigurationStructureFailed").get<ConfigurationStructureFailed>());
        x.set_cause(j.at("Cause").get<AdministrativeState>());
        x.set_e2_sm_ccc_control_outcome_format2(j.at("E2SM-CCC-ControlOutcomeFormat2").get<E2SmCccControlOutcomeFormat2>());
        x.set_list_of_cells_for_control_outcome(j.at("ListOfCellsForControlOutcome").get<GEnbIdList>());
        x.set_cell_control_outcome(j.at("CellControlOutcome").get<CellControlOutcome>());
        x.set_ric_query_header(j.at("RIC-Query-Header").get<RicQueryHeader>());
        x.set_query_header_format(j.at("QueryHeaderFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_query_header_format1(j.at("E2SM-CCC-QueryHeaderFormat1").get<E2SmCccHeaderFormat1>());
        x.set_ric_query_definition(j.at("RIC-Query-Definition").get<RicQueryDefinition>());
        x.set_query_definition_format(j.at("QueryDefinitionFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_query_definition_format1(j.at("E2SM-CCC-QueryDefinitionFormat1").get<E2SmCccQueryDefinitionFormat1>());
        x.set_list_of_nodelevel_ran_configuration_structures_for_query(j.at("ListOfNodelevelRanConfigurationStructuresForQuery").get<GEnbIdList>());
        x.set_nodelevel_ran_configuration_structures_for_query(j.at("NodelevelRanConfigurationStructuresForQuery").get<ConfigurationStructuresForQuery>());
        x.set_e2_sm_ccc_query_definition_format2(j.at("E2SM-CCC-QueryDefinitionFormat2").get<E2SmCccQueryDefinitionFormat2>());
        x.set_list_of_cells_to_be_queried_for_query(j.at("ListOfCellsToBeQueriedForQuery").get<GEnbIdList>());
        x.set_cells_to_be_queried(j.at("CellsToBeQueried").get<CellsToBeQueried>());
        x.set_list_of_celllevel_configuration_structures_for_query(j.at("ListOfCelllevelConfigurationStructuresForQuery").get<GEnbIdList>());
        x.set_celllevel_configuration_structures_for_query(j.at("CelllevelConfigurationStructuresForQuery").get<ConfigurationStructuresForQuery>());
        x.set_ric_query_outcome(j.at("RIC-Query-Outcome").get<RicQueryOutcome>());
        x.set_query_outcome_format(j.at("QueryOutcomeFormat").get<ActionDefinitionFormat>());
        x.set_e2_sm_ccc_query_outcome_format1(j.at("E2SM-CCC-QueryOutcomeFormat1").get<E2SmCccQueryOutcomeFormat1>());
        x.set_list_of_configuration_structures_to_be_reported_for_query(j.at("ListOfConfigurationStructuresToBeReportedForQuery").get<GEnbIdList>());
        x.set_configuration_structures_to_be_reported_for_query(j.at("ConfigurationStructuresToBeReportedForQuery").get<ConfigurationStructuresToBeReportedForQuery>());
        x.set_e2_sm_ccc_query_outcome_format2(j.at("E2SM-CCC-QueryOutcomeFormat2").get<E2SmCccQueryOutcomeFormat2>());
        x.set_list_of_cells_to_be_reported_for_query(j.at("ListOfCellsToBeReportedForQuery").get<GEnbIdList>());
        x.set_cells_to_be_reported_for_query(j.at("CellsToBeReportedForQuery").get<CellsToBeReportedForQuery>());
    }

    inline void to_json(json & j, const Schemas & x) {
        j = json::object();
        j["GnbId"] = x.get_gnb_id();
        j["GnbIdLength"] = x.get_gnb_id_length();
        j["GnbName"] = x.get_gnb_name();
        j["GnbDuId"] = x.get_gnb_du_id();
        j["GnbCuUpId"] = x.get_gnb_cu_up_id();
        j["Sst"] = x.get_sst();
        j["Snssai"] = x.get_snssai();
        j["SnssaiList"] = x.get_snssai_list();
        j["Mcc"] = x.get_mcc();
        j["Mnc"] = x.get_mnc();
        j["PlmnId"] = x.get_plmn_id();
        j["PlmnIdList"] = x.get_plmn_id_list();
        j["PlmnInfo"] = x.get_plmn_info();
        j["PlmnInfoList"] = x.get_plmn_info_list();
        j["GGnbId"] = x.get_g_gnb_id();
        j["GEnbId"] = x.get_g_enb_id();
        j["GGnbIdList"] = x.get_g_gnb_id_list();
        j["GEnbIdList"] = x.get_g_enb_id_list();
        j["NrPci"] = x.get_nr_pci();
        j["NrTac"] = x.get_nr_tac();
        j["OperationalState"] = x.get_operational_state();
        j["AdministrativeState"] = x.get_administrative_state();
        j["CellState"] = x.get_cell_state();
        j["CyclicPrefix"] = x.get_cyclic_prefix();
        j["BwpContext"] = x.get_bwp_context();
        j["IsInitialBwp"] = x.get_is_initial_bwp();
        j["SubCarrierSpacing"] = x.get_sub_carrier_spacing();
        j["SsbPeriodicity"] = x.get_ssb_periodicity();
        j["SsbDuration"] = x.get_ssb_duration();
        j["SsbSubCarrierSpacing"] = x.get_ssb_sub_carrier_spacing();
        j["ResourceType"] = x.get_resource_type();
        j["RrmPolicyMember"] = x.get_rrm_policy_member();
        j["RrmPolicyMemberList"] = x.get_rrm_policy_member_list();
        j["5QiList"] = x.get_the_5__qi_list();
        j["PartitionFlowList"] = x.get_partition_flow_list();
        j["PartitionList"] = x.get_partition_list();
        j["PrbBlankingConfigurationList"] = x.get_prb_blanking_configuration_list();
        j["EsObjective"] = x.get_es_objective();
        j["PerfObjective"] = x.get_perf_objective();
        j["PerfObjectiveList"] = x.get_perf_objective_list();
        j["SleepMode"] = x.get_sleep_mode();
        j["SleepModes"] = x.get_sleep_modes();
        j["SupportedTrxControlMask"] = x.get_supported_trx_control_mask();
        j["SupportedTrxControlMasks"] = x.get_supported_trx_control_masks();
        j["EnergySavingCapabilityCommonInfo"] = x.get_energy_saving_capability_common_info();
        j["AsmCapabilityInfo"] = x.get_asm_capability_info();
        j["TrxControlCapabilityInfo"] = x.get_trx_control_capability_info();
        j["OruCapabilities"] = x.get_oru_capabilities();
        j["OnDurationTimer"] = x.get_on_duration_timer();
        j["CycleStartOffset"] = x.get_cycle_start_offset();
        j["tPolarizationItem"] = x.get_t_polarization_item();
        j["rPolarizationItem"] = x.get_r_polarization_item();
        j["TxArrayItem"] = x.get_tx_array_item();
        j["RxArrayItem"] = x.get_rx_array_item();
        j["TxArrayList"] = x.get_tx_array_list();
        j["RxArrayList"] = x.get_rx_array_list();
        j["OruUserPlaneConfiguration"] = x.get_oru_user_plane_configuration();
        j["O-GnbCuCpFunction"] = x.get_o_gnb_cu_cp_function();
        j["O-GnbCuUpFunction"] = x.get_o_gnb_cu_up_function();
        j["O-GnbDuFunction"] = x.get_o_gnb_du_function();
        j["O-NrCellCu"] = x.get_o_nr_cell_cu();
        j["O-NrCellDu"] = x.get_o_nr_cell_du();
        j["O-RRMPolicyRatio"] = x.get_o_rrm_policy_ratio();
        j["O-Bwp"] = x.get_o_bwp();
        j["O-CESManagementFunction"] = x.get_o_ces_management_function();
        j["O-NESPolicy"] = x.get_o_nes_policy();
        j["O-PRBBlankingPolicy"] = x.get_o_prb_blanking_policy();
        j["O-CellDTXDRXConfig"] = x.get_o_cell_dtxdrx_config();
        j["O-RUInfo"] = x.get_o_ru_info();
        j["E2SM-CCC-RAN-Configuration-Structure"] = x.get_e2_sm_ccc_ran_configuration_structure();
        j["RIC-Indication-Header"] = x.get_ric_indication_header();
        j["IndicationHeaderFormat"] = x.get_indication_header_format();
        j["E2SM-CCC-IndicationHeaderFormat1"] = x.get_e2_sm_ccc_indication_header_format1();
        j["RIC-Indication-Message"] = x.get_ric_indication_message();
        j["IndicationMessageFormat"] = x.get_indication_message_format();
        j["E2SM-CCC-IndicationMessageFormat1"] = x.get_e2_sm_ccc_indication_message_format1();
        j["ListOfConfigurationsReported"] = x.get_list_of_configurations_reported();
        j["ConfigurationStructure"] = x.get_configuration_structure();
        j["ValuesOfAttributes"] = x.get_values_of_attributes();
        j["E2SM-CCC-IndicationMessageFormat2"] = x.get_e2_sm_ccc_indication_message_format2();
        j["ListOfCellsReported"] = x.get_list_of_cells_reported();
        j["CellReported"] = x.get_cell_reported();
        j["CellGlobalId"] = x.get_cell_global_id();
        j["NR-CGI"] = x.get_nr_cgi();
        j["NRCellIdentity"] = x.get_nr_cell_identity();
        j["EUTRA-CGI"] = x.get_eutra_cgi();
        j["EUTRACellIdentity"] = x.get_eutra_cell_identity();
        j["RIC-Control-Header"] = x.get_ric_control_header();
        j["ControlHeaderFormat"] = x.get_control_header_format();
        j["E2SM-CCC-ControlHeaderFormat1"] = x.get_e2_sm_ccc_control_header_format1();
        j["RIC-Control-Message"] = x.get_ric_control_message();
        j["ControlMessageFormat"] = x.get_control_message_format();
        j["E2SM-CCC-ControlMessageFormat1"] = x.get_e2_sm_ccc_control_message_format1();
        j["ListOfConfigurationStructures"] = x.get_list_of_configuration_structures();
        j["ConfigurationStructureWrite"] = x.get_configuration_structure_write();
        j["E2SM-CCC-ControlMessageFormat2"] = x.get_e2_sm_ccc_control_message_format2();
        j["ListOfCellsControlled"] = x.get_list_of_cells_controlled();
        j["CellControlled"] = x.get_cell_controlled();
        j["RANFunctionDefinition"] = x.get_ran_function_definition();
        j["RANFunctionName"] = x.get_ran_function_name();
        j["ListOfSupportedRANConfigurationStructures"] = x.get_list_of_supported_ran_configuration_structures();
        j["RANConfigurationStructure"] = x.get_ran_configuration_structure();
        j["ListOfSupportedAttributes"] = x.get_list_of_supported_attributes();
        j["Attribute"] = x.get_attribute();
        j["RICServices"] = x.get_ric_services();
        j["EventTrigger"] = x.get_event_trigger();
        j["ListOfSupportedEventTriggerStyles"] = x.get_list_of_supported_event_trigger_styles();
        j["EventTriggerStyle"] = x.get_event_trigger_style();
        j["ReportService"] = x.get_report_service();
        j["ListOfSupportedReportStyles"] = x.get_list_of_supported_report_styles();
        j["ReportStyle"] = x.get_report_style();
        j["EventTriggerStyleType"] = x.get_event_trigger_style_type();
        j["InsertService"] = x.get_insert_service();
        j["ControlService"] = x.get_control_service();
        j["ListOfSupportedControlStyles"] = x.get_list_of_supported_control_styles();
        j["ControlStyle"] = x.get_control_style();
        j["PolicyService"] = x.get_policy_service();
        j["QueryService"] = x.get_query_service();
        j["ListOfSupportedQueryStyles"] = x.get_list_of_supported_query_styles();
        j["QueryStyle"] = x.get_query_style();
        j["ListOfCellsForRANFunctionDefinition"] = x.get_list_of_cells_for_ran_function_definition();
        j["CellForRANFunctionDefinition"] = x.get_cell_for_ran_function_definition();
        j["RICEventTriggerDefinition"] = x.get_ric_event_trigger_definition();
        j["EventTriggerDefinitionFormat"] = x.get_event_trigger_definition_format();
        j["E2SM-CCC-EventTriggerDefinition-Format1"] = x.get_e2_sm_ccc_event_trigger_definition_format1();
        j["ListOfRANConfigurationStructuresForEventTrigger"] = x.get_list_of_ran_configuration_structures_for_event_trigger();
        j["RANConfigurationStructureForEventTrigger"] = x.get_ran_configuration_structure_for_event_trigger();
        j["E2SM-CCC-EventTriggerDefinition-Format2"] = x.get_e2_sm_ccc_event_trigger_definition_format2();
        j["ListOfCellLevelConfigurationStructuresForEventTrigger"] = x.get_list_of_cell_level_configuration_structures_for_event_trigger();
        j["CellLevelConfigurationStructureForEventTrigger"] = x.get_cell_level_configuration_structure_for_event_trigger();
        j["E2SM-CCC-EventTriggerDefinition-Format3"] = x.get_e2_sm_ccc_event_trigger_definition_format3();
        j["RICActionDefinition"] = x.get_ric_action_definition();
        j["ActionDefinitionFormat"] = x.get_action_definition_format();
        j["E2SM-CCC-ActionDefinitionFormat1"] = x.get_e2_sm_ccc_action_definition_format1();
        j["ListOfRANConfigurationStructuresForADF"] = x.get_list_of_ran_configuration_structures_for_adf();
        j["RANConfigurationStructureForADF"] = x.get_ran_configuration_structure_for_adf();
        j["AttributeName"] = x.get_attribute_name();
        j["E2SM-CCC-ActionDefinitionFormat2"] = x.get_e2_sm_ccc_action_definition_format2();
        j["ListOfCellConfigurationsToBeReportedForADF"] = x.get_list_of_cell_configurations_to_be_reported_for_adf();
        j["CellConfigurationToBeReportedForADF"] = x.get_cell_configuration_to_be_reported_for_adf();
        j["RIC-Control-Outcome"] = x.get_ric_control_outcome();
        j["ControlOutcomeFormat"] = x.get_control_outcome_format();
        j["E2SM-CCC-ControlOutcomeFormat1"] = x.get_e2_sm_ccc_control_outcome_format1();
        j["RanConfigurationStructuresAcceptedList"] = x.get_ran_configuration_structures_accepted_list();
        j["ConfigurationStructureAccepted"] = x.get_configuration_structure_accepted();
        j["RanConfigurationStructuresFailedList"] = x.get_ran_configuration_structures_failed_list();
        j["ConfigurationStructureFailed"] = x.get_configuration_structure_failed();
        j["Cause"] = x.get_cause();
        j["E2SM-CCC-ControlOutcomeFormat2"] = x.get_e2_sm_ccc_control_outcome_format2();
        j["ListOfCellsForControlOutcome"] = x.get_list_of_cells_for_control_outcome();
        j["CellControlOutcome"] = x.get_cell_control_outcome();
        j["RIC-Query-Header"] = x.get_ric_query_header();
        j["QueryHeaderFormat"] = x.get_query_header_format();
        j["E2SM-CCC-QueryHeaderFormat1"] = x.get_e2_sm_ccc_query_header_format1();
        j["RIC-Query-Definition"] = x.get_ric_query_definition();
        j["QueryDefinitionFormat"] = x.get_query_definition_format();
        j["E2SM-CCC-QueryDefinitionFormat1"] = x.get_e2_sm_ccc_query_definition_format1();
        j["ListOfNodelevelRanConfigurationStructuresForQuery"] = x.get_list_of_nodelevel_ran_configuration_structures_for_query();
        j["NodelevelRanConfigurationStructuresForQuery"] = x.get_nodelevel_ran_configuration_structures_for_query();
        j["E2SM-CCC-QueryDefinitionFormat2"] = x.get_e2_sm_ccc_query_definition_format2();
        j["ListOfCellsToBeQueriedForQuery"] = x.get_list_of_cells_to_be_queried_for_query();
        j["CellsToBeQueried"] = x.get_cells_to_be_queried();
        j["ListOfCelllevelConfigurationStructuresForQuery"] = x.get_list_of_celllevel_configuration_structures_for_query();
        j["CelllevelConfigurationStructuresForQuery"] = x.get_celllevel_configuration_structures_for_query();
        j["RIC-Query-Outcome"] = x.get_ric_query_outcome();
        j["QueryOutcomeFormat"] = x.get_query_outcome_format();
        j["E2SM-CCC-QueryOutcomeFormat1"] = x.get_e2_sm_ccc_query_outcome_format1();
        j["ListOfConfigurationStructuresToBeReportedForQuery"] = x.get_list_of_configuration_structures_to_be_reported_for_query();
        j["ConfigurationStructuresToBeReportedForQuery"] = x.get_configuration_structures_to_be_reported_for_query();
        j["E2SM-CCC-QueryOutcomeFormat2"] = x.get_e2_sm_ccc_query_outcome_format2();
        j["ListOfCellsToBeReportedForQuery"] = x.get_list_of_cells_to_be_reported_for_query();
        j["CellsToBeReportedForQuery"] = x.get_cells_to_be_reported_for_query();
    }

    inline void from_json(const json & j, Components& x) {
        x.set_schemas(j.at("schemas").get<Schemas>());
    }

    inline void to_json(json & j, const Components & x) {
        j = json::object();
        j["schemas"] = x.get_schemas();
    }

    inline void from_json(const json & j, Info& x) {
        x.set_title(j.at("title").get<std::string>());
        x.set_version(j.at("version").get<std::string>());
        x.set_description(j.at("description").get<std::string>());
    }

    inline void to_json(json & j, const Info & x) {
        j = json::object();
        j["title"] = x.get_title();
        j["version"] = x.get_version();
        j["description"] = x.get_description();
    }

    inline void from_json(const json & j, Paths& x) {
    }

    inline void to_json(json & j, const Paths & x) {
        j = json::object();
    }

    inline void from_json(const json & j, E2SmCcc& x) {
        x.set_openapi(j.at("openapi").get<std::string>());
        x.set_info(j.at("info").get<Info>());
        x.set_paths(j.at("paths").get<Paths>());
        x.set_components(j.at("components").get<Components>());
    }

    inline void to_json(json & j, const E2SmCcc & x) {
        j = json::object();
        j["openapi"] = x.get_openapi();
        j["info"] = x.get_info();
        j["paths"] = x.get_paths();
        j["components"] = x.get_components();
    }

    inline void from_json(const json & j, EutraCellIdentityType & x) {
        if (j == "boolean") x = EutraCellIdentityType::BOOLEAN;
        else if (j == "integer") x = EutraCellIdentityType::INTEGER;
        else if (j == "number") x = EutraCellIdentityType::NUMBER;
        else if (j == "object") x = EutraCellIdentityType::OBJECT;
        else if (j == "string") x = EutraCellIdentityType::STRING;
        else { throw std::runtime_error("Input JSON does not conform to schema!"); }
    }

    inline void to_json(json & j, const EutraCellIdentityType & x) {
        switch (x) {
            case EutraCellIdentityType::BOOLEAN: j = "boolean"; break;
            case EutraCellIdentityType::INTEGER: j = "integer"; break;
            case EutraCellIdentityType::NUMBER: j = "number"; break;
            case EutraCellIdentityType::OBJECT: j = "object"; break;
            case EutraCellIdentityType::STRING: j = "string"; break;
            default: throw std::runtime_error("Unexpected value in enumeration \"EutraCellIdentityType\": " + std::to_string(static_cast<int>(x)));
        }
    }

    inline void from_json(const json & j, The5QiListType & x) {
        if (j == "array") x = The5QiListType::ARRAY;
        else { throw std::runtime_error("Input JSON does not conform to schema!"); }
    }

    inline void to_json(json & j, const The5QiListType & x) {
        switch (x) {
            case The5QiListType::ARRAY: j = "array"; break;
            default: throw std::runtime_error("Unexpected value in enumeration \"The5QiListType\": " + std::to_string(static_cast<int>(x)));
        }
    }
}
