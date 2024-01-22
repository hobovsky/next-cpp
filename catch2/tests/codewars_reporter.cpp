#include <iostream>

#include <catch_amalgamated.hpp>

// TODO Complete custom reporter
// - https://github.com/catchorg/Catch2/blob/devel/docs/reporters.md
// - https://github.com/catchorg/Catch2/blob/devel/docs/reporter-events.md
// - https://github.com/catchorg/Catch2/blob/devel/docs/test-cases-and-sections.md
class CodewarsReporter : public Catch::StreamingReporterBase {

private:
    bool inTest = false;

public:

    CodewarsReporter(Catch::ReporterConfig&& config) :
        StreamingReporterBase{ CATCH_MOVE(config) } {

        //m_preferences.shouldRedirectStdOut = true;
        // TBD: Do we want to report all assertions? XML reporter does
        //      not, but for machine-parseable reporters I think the answer
        //      should be yes.
        m_preferences.shouldReportAllAssertions = true;
    }

    using StreamingReporterBase::StreamingReporterBase;

    static std::string getDescription() {
        return "Reporter for Codewars";
    }

    // Emitted before the first test case is executed.
    void testRunStarting(Catch::TestRunInfo const& testRunInfo) override {  
        std::cout << "testRunStarting " << testRunInfo.name << '\n';
    }

    // Emitted after all the test cases have been executed.
    void testRunEnded( Catch::TestRunStats const& testRunStats) override {
        std::cout << "testRunEnded\n";
    }

    void sectionStarting( Catch::SectionInfo const& sectionInfo) override {
        // Cannot be used for group? Each testcase has implicit section.
        if (inTest) return;
        std::cout << "\n<DESCRIBE::>" << sectionInfo.name << '\n';
    }

    void sectionEnded( Catch::SectionStats const& sectionStats) override {
        if (inTest) return;
        std::cout << "\n<COMPLETEDIN::>\n";
    }

    void testCaseStarting( Catch::TestCaseInfo const& testInfo) override {
        if (inTest) return;
        std::cout << "\n<DESCRIBE::>" << testInfo.name << '\n';
    }

    void testCaseEnded( Catch::TestCaseStats const& testCaseStats) override {
        if (inTest) return;
        std::cout << "\n<COMPLETEDIN::>\n";
    }

    void testCasePartialStarting(Catch::TestCaseInfo const& testInfo, uint64_t partNumber) override {
        std::cout << "\n<DESCRIBE::>" << testInfo.name << '#' << partNumber << '\n';
        // inTest = true;
    }

    void testCasePartialEnded(Catch::TestCaseStats const& testCaseStats, uint64_t partNumber) override {
        if (inTest) return;
        std::cout << "\n<COMPLETEDIN::>\n";
    }

    void assertionStarting(Catch::AssertionInfo const& info) override {
        std::cout << "\n<IT::>Assertion" << '\n';
    }
    void assertionEnded(Catch::AssertionStats const& statss) override {
        auto stats = statss.assertionResult;
        std::cout << '\n' << (stats.isOk() ? "<PASSED::> " : "<FAILED::>") << (stats.hasMessage() ? stats.getMessage() : (stats.isOk() ? "Test passed" : "Test failed")) << '\n';
        std::cout << "\n<COMPLETEDIN::>\n";
    }

};


CATCH_REGISTER_REPORTER("codewars", CodewarsReporter)
