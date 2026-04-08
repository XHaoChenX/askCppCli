#pragma once

#include <string>

/**
 * @brief Ask the dabai agent a question and get the response
 * @param question The user's question
 * @return The agent's response, or empty string on error
 */
std::string ask_dabai(const std::string& question);
