#include "all_csv_configs.h"

#include <string_view>

#include "csv_config_util.h"

namespace tests {

namespace {
/// create `CSVConfig` using relative path to the directory with test data
CSVConfig CreateCsvConfig(std::string_view filename, char separator, bool has_header) {
    return {test_data_dir / filename, separator, has_header};
}
}  // namespace

CSVConfig const kWDC_astronomical = CreateCsvConfig("WDC_astronomical.csv", ',', true);
CSVConfig const kWDC_symbols = CreateCsvConfig("WDC_symbols.csv", ',', true);
CSVConfig const kWDC_science = CreateCsvConfig("WDC_science.csv", ',', true);
CSVConfig const kWDC_satellites = CreateCsvConfig("WDC_satellites.csv", ',', true);
CSVConfig const kWDC_appearances = CreateCsvConfig("WDC_appearances.csv", ',', true);
CSVConfig const kWDC_astrology = CreateCsvConfig("WDC_astrology.csv", ',', true);
CSVConfig const kWDC_game = CreateCsvConfig("WDC_game.csv", ',', true);
CSVConfig const kWDC_kepler = CreateCsvConfig("WDC_kepler.csv", ',', true);
CSVConfig const kWDC_planetz = CreateCsvConfig("WDC_planetz.csv", ',', true);
CSVConfig const kWDC_age = CreateCsvConfig("WDC_age.csv", ',', true);
CSVConfig const kTestWide = CreateCsvConfig("TestWide.csv", ',', true);
CSVConfig const kabalone = CreateCsvConfig("abalone.csv", ',', false);
CSVConfig const kiris = CreateCsvConfig("iris.csv", ',', false);
CSVConfig const kadult = CreateCsvConfig("adult.csv", ';', false);
CSVConfig const kbreast_cancer = CreateCsvConfig("breast_cancer.csv", ',', true);
CSVConfig const kCIPublicHighway10k = CreateCsvConfig("CIPublicHighway10k.csv", ',', true);
CSVConfig const kneighbors10k = CreateCsvConfig("neighbors10k.csv", ',', true);
CSVConfig const kneighbors50k = CreateCsvConfig("neighbors50k.csv", ',', true);
CSVConfig const kneighbors100k = CreateCsvConfig("neighbors100k.csv", ',', true);
CSVConfig const kCIPublicHighway700 = CreateCsvConfig("CIPublicHighway700.csv", ',', true);
CSVConfig const kEpicVitals = CreateCsvConfig("EpicVitals.csv", '|', true);
CSVConfig const kEpicMeds = CreateCsvConfig("EpicMeds.csv", '|', true);
CSVConfig const kiowa1kk = CreateCsvConfig("iowa1kk.csv", ',', true);
CSVConfig const kfd_reduced_30 = CreateCsvConfig("fd-reduced-30.csv", ',', true);
CSVConfig const kflight_1k = CreateCsvConfig("flight_1k.csv", ';', true);
CSVConfig const kplista_1k = CreateCsvConfig("plista_1k.csv", ';', false);
CSVConfig const kletter = CreateCsvConfig("letter.csv", ',', false);
CSVConfig const kCIPublicHighway = CreateCsvConfig("CIPublicHighway.csv", ',', true);
CSVConfig const kLegacyPayors = CreateCsvConfig("LegacyPayors.csv", '|', true);
CSVConfig const kTestEmpty = CreateCsvConfig("TestEmpty.csv", ',', true);
CSVConfig const kTestSingleColumn = CreateCsvConfig("TestSingleColumn.csv", ',', true);
CSVConfig const kTestLong = CreateCsvConfig("TestLong.csv", ',', true);
CSVConfig const kTestFD = CreateCsvConfig("TestFD.csv", ',', true);
CSVConfig const kIndTestWide2 = CreateCsvConfig("ind_data/TestWide2.csv", ',', false);
CSVConfig const kIndTestEmpty = CreateCsvConfig("ind_data/Empty.csv", ',', true);
CSVConfig const kIndTestPlanets = CreateCsvConfig("ind_data/Planets.csv", ',', false);
CSVConfig const kIndTest3aryInds = CreateCsvConfig("ind_data/Test-3ary-inds.csv", ',', false);
CSVConfig const kIndTestTableFirst = CreateCsvConfig("ind_data/two_tables/first.csv", ',', false);
CSVConfig const kIndTestTableSecond = CreateCsvConfig("ind_data/two_tables/second.csv", ',', false);
CSVConfig const kIndTestNulls = CreateCsvConfig("INDTestNulls.csv", ',', true);
CSVConfig const kTestZeros = CreateCsvConfig("TestZeros.csv", ',', true);
CSVConfig const kNullEmpty = CreateCsvConfig("NullEmpty.csv", ',', true);
CSVConfig const kSimpleTypes = CreateCsvConfig("SimpleTypes.csv", ',', true);
CSVConfig const krules_book = CreateCsvConfig("transactional_data/rules-book.csv", ',', false);
CSVConfig const krules_presentation_extended =
        CreateCsvConfig("transactional_data/rules-presentation-extended.csv", ',', false);
CSVConfig const krules_presentation =
        CreateCsvConfig("transactional_data/rules-presentation.csv", ',', false);
CSVConfig const krules_synthetic_2 =
        CreateCsvConfig("transactional_data/rules-synthetic-2.csv", ',', false);
CSVConfig const krules_kaggle_rows =
        CreateCsvConfig("transactional_data/rules-kaggle-rows.csv", ',', true);
CSVConfig const ktennis = CreateCsvConfig("cfd_data/tennis.csv", ',', true);
CSVConfig const kmushroom = CreateCsvConfig("cfd_data/mushroom.csv", ',', true);
CSVConfig const kTestDataStats = CreateCsvConfig("TestDataStats.csv", ',', false);
CSVConfig const kTestMetric = CreateCsvConfig("TestMetric.csv", ',', true);
CSVConfig const kBernoulliRelation = CreateCsvConfig("BernoulliRelation.csv", ',', true);
CSVConfig const kACShippingDates = CreateCsvConfig("ACShippingDates.csv", ',', true);
CSVConfig const kSimpleTypos = CreateCsvConfig("SimpleTypos.csv", ',', true);
CSVConfig const kTest1 = CreateCsvConfig("Test1.csv", ',', true);
CSVConfig const kProbeTest1 = CreateCsvConfig("ProbeTest1.csv", ',', true);
CSVConfig const kProbeTest2 = CreateCsvConfig("ProbeTest2.csv", ',', true);
CSVConfig const kTestParse = CreateCsvConfig("TestParse.csv", ',', false);
}  // namespace tests
