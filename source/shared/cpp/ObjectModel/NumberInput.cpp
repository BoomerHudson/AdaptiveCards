#include "pch.h"
#include "NumberInput.h"
#include "ParseUtil.h"

using namespace AdaptiveSharedNamespace;

NumberInput::NumberInput() :
    BaseInputElement(CardElementType::NumberInput),
    m_min(std::numeric_limits<int>::min()),
    m_max(std::numeric_limits<int>::max())
{
    PopulateKnownPropertiesSet();
}

Json::Value NumberInput::SerializeToJsonValue()
{
    Json::Value root = BaseInputElement::SerializeToJsonValue();

    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Max)] = GetMax();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Min)] = GetMin();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Placeholder)] = GetPlaceholder();
    root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value)] = GetValue();

    return root;
}

std::string NumberInput::GetPlaceholder() const
{
    return m_placeholder;
}

void NumberInput::SetPlaceholder(const std::string value)
{
    m_placeholder = value;
}

int NumberInput::GetValue() const
{
    return m_value;
}

void NumberInput::SetValue(const int value)
{
    m_value = value;
}

int NumberInput::GetMax() const
{
    return m_max;
}

void NumberInput::SetMax(const int value)
{
    m_max = value;
}

int NumberInput::GetMin() const
{
    return m_min;
}

void NumberInput::SetMin(const int value)
{
    m_min = value;
}

std::shared_ptr<BaseCardElement> NumberInputParser::Deserialize(
    std::shared_ptr<ElementParserRegistration>,
    std::shared_ptr<ActionParserRegistration>,
    const Json::Value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::NumberInput);

    std::shared_ptr<NumberInput> numberInput = BaseInputElement::Deserialize<NumberInput>(json);

    numberInput->SetPlaceholder(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Placeholder));
    numberInput->SetValue(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Value, 0));
    numberInput->SetMax(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Max, std::numeric_limits<int>::max()));
    numberInput->SetMin(ParseUtil::GetInt(json, AdaptiveCardSchemaKey::Min, std::numeric_limits<int>::min()));

    return numberInput;
}

std::shared_ptr<BaseCardElement> NumberInputParser::DeserializeFromString(
    std::shared_ptr<ElementParserRegistration> elementParserRegistration,
    std::shared_ptr<ActionParserRegistration> actionParserRegistration,
    const std::string& jsonString)
{
    return NumberInputParser::Deserialize(elementParserRegistration, actionParserRegistration, ParseUtil::GetJsonValueFromString(jsonString));
}

void NumberInput::PopulateKnownPropertiesSet() 
{
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Placeholder));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Max));
    m_knownProperties.insert(AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Min));
}
