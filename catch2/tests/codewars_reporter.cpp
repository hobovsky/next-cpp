#include <catch2/reporters/catch_reporter_helpers.hpp>
#include <catch2/reporters/catch_reporter_streaming_base.hpp>
#include <catch2/catch_test_case_info.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include <catch2/catch_timer.hpp>

#include <iostream>

// TODO Complete custom reporter
// - https://github.com/catchorg/Catch2/blob/devel/docs/reporters.md
// - https://github.com/catchorg/Catch2/blob/devel/docs/reporter-events.md
// - https://github.com/catchorg/Catch2/blob/devel/docs/test-cases-and-sections.md
class CodewarsReporter : public Catch::StreamingReporterBase {
public:
    using StreamingReporterBase::StreamingReporterBase;

    static std::string getDescription() {
        return "Reporter for Codewars";
    }

    // Emitted before the first test case is executed.
    void testRunStarting(Catch::TestRunInfo const& testRunInfo) override {
        std::cout << "testRunStarting " << testRunInfo.name << '\n';
    }

    // Emitted after all the test cases have been executed.
    void testRunEnded(__attribute__((unused)) Catch::TestRunStats const& testRunStats) override {
        std::cout << "testRunEnded\n";
    }

    void sectionStarting(__attribute__((unused)) Catch::SectionInfo const& sectionInfo) override {
        // Cannot be used for group? Each testcase has implicit section.
        std::cout << "\n<DESCRIBE::>" << sectionInfo.name << '\n';
    }

    void sectionEnded(__attribute__((unused)) Catch::SectionStats const& sectionStats) override {
        std::cout << "\n<COMPLETEDIN::>\n";
    }

    void testCaseStarting(__attribute__((unused)) Catch::TestCaseInfo const& testInfo) override {
        std::cout << "\n<IT::>" << testInfo.name << '\n';
    }

    void testCaseEnded(__attribute__((unused)) Catch::TestCaseStats const& testCaseStats) override {
        std::cout << "\n<COMPLETEDIN::>\n";
    }

    void testCasePartialStarting(Catch::TestCaseInfo const& testInfo, uint64_t partNumber) override {
        std::cout << "TestCaseStartingPartial: " << testInfo.name << '#' << partNumber << '\n';
    }

    void testCasePartialEnded(Catch::TestCaseStats const& testCaseStats, uint64_t partNumber) override {
        std::cout << "TestCasePartialEnded: " << testCaseStats.testInfo->name << '#' << partNumber << '\n';
    }
};


CATCH_REGISTER_REPORTER("codewars", CodewarsReporter)
