// In this test file, I have written tests that cover the cases in which the world ladder can
// produce results. These cases include finding a valid path, finding multiple valid paths,
// finding a path where there is only one letter difference between the start and end word,
// as well as the case when there is no valid path
#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include <catch2/catch.hpp>

TEST_CASE("finds a valid path (dealt -> spice)") {
	std::unordered_set<std::string> test_lexicon =
	   {"dealt", "spice", "spars", "space", "dears", "deals", "sears", "spare"};

	auto const ladders = word_ladder::generate("dealt", "spice", test_lexicon);

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(
	   std::count(
	      ladders.begin(),
	      ladders.end(),
	      std::vector<std::string>{"dealt", "deals", "dears", "sears", "spars", "spare", "space", "spice"})
	   == 1);
}

TEST_CASE("finds a valid path (day -> bag)") {
	std::unordered_set<std::string> test_lexicon = {"day", "dag", "bag", "bog"};

	auto const ladders = word_ladder::generate("day", "bag", test_lexicon);

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"day", "dag", "bag"})
	      == 1);
}

TEST_CASE("finds a valid path with only one letter difference (bed -> bee)") {
	std::unordered_set<std::string> test_lexicon = {"bee", "bed", "beg", "bay"};

	auto const ladders = word_ladder::generate("bed", "bee", test_lexicon);

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"bed", "bee"}) == 1);
}

TEST_CASE("finds a valid path with only one letter difference (fat -> fan)") {
	std::unordered_set<std::string> test_lexicon = {"fat", "fan", "fad", "fam"};

	auto const ladders = word_ladder::generate("fat", "fan", test_lexicon);

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"fat", "fan"}) == 1);
}

TEST_CASE("finds multiple valid paths (work -> play)") {
	std::unordered_set<std::string> test_lexicon =
	   {"work", "worm", "form", "foam", "flam", "flay", "play", "word", "wood", "pood", "plod", "ploy"};

	auto const ladders = word_ladder::generate("work", "play", test_lexicon);

	CHECK(std::size(ladders) == 2);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(),
	                 ladders.end(),
	                 std::vector<std::string>{"work", "word", "wood", "pood", "plod", "ploy", "play"})
	      == 1);

	CHECK(std::count(ladders.begin(),
	                 ladders.end(),
	                 std::vector<std::string>{"work", "worm", "form", "foam", "flam", "flay", "play"})
	      == 1);
}

TEST_CASE("finds multiple valid paths (awake -> sleep)") {
	std::unordered_set<std::string> test_lexicon = {"awake",
	                                                "aware",
	                                                "sware",
	                                                "share",
	                                                "sharn",
	                                                "shawn",
	                                                "shewn",
	                                                "sheen",
	                                                "sheep",
	                                                "sleep",
	                                                "shire",
	                                                "shirr",
	                                                "shier",
	                                                "sheer"};

	auto const ladders = word_ladder::generate("awake", "sleep", test_lexicon);

	CHECK(std::size(ladders) == 2);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(),
	                 ladders.end(),
	                 std::vector<std::string>{"awake",
	                                          "aware",
	                                          "sware",
	                                          "share",
	                                          "sharn",
	                                          "shawn",
	                                          "shewn",
	                                          "sheen",
	                                          "sheep",
	                                          "sleep"})
	      == 1);

	CHECK(std::count(ladders.begin(),
	                 ladders.end(),
	                 std::vector<std::string>{"awake",
	                                          "aware",
	                                          "sware",
	                                          "share",
	                                          "shire",
	                                          "shirr",
	                                          "shier",
	                                          "sheer",
	                                          "sheep",
	                                          "sleep"})
	      == 1);
}

TEST_CASE("finds no path (test -> word)") {
	std::unordered_set<std::string> test_lexicon = {"test", "best", "jest", "lest", "word"};

	auto const ladders = word_ladder::generate("test", "word", test_lexicon);

	CHECK(std::size(ladders) == 0);
}
