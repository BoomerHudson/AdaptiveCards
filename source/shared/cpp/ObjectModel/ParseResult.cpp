#include "pch.h"
#include "ParseResult.h"
#include "ParseResult.h"
#include "SharedAdaptiveCard.h"

using namespace AdaptiveSharedNamespaceRef;

ParseResult::ParseResult(
    std::shared_ptr<AdaptiveCard> adaptiveCard,
    std::vector<std::shared_ptr<AdaptiveCardParseWarning>> warnings) :
    m_adaptiveCard(adaptiveCard),
    m_warnings(warnings)
{
}

std::shared_ptr<AdaptiveCard> ParseResult::GetAdaptiveCard()
{
    return m_adaptiveCard;
}

std::vector<std::shared_ptr<AdaptiveCardParseWarning>> ParseResult::GetWarnings()
{
    return m_warnings;
}
