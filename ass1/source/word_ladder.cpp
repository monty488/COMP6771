#include <comp6771/word_ladder.hpp>
#include <unordered_map>
#include <queue>

namespace word_ladder {

	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {
		std::vector<std::vector<std::string>> paths_found;
		std::queue<std::vector<std::string>> queue;
		std::unordered_map<std::string, std::vector<std::string>::size_type> distance_to_word;

		// Create the starting ladder (ladder with only the starting word)
		std::vector<std::string> ladder_start;
		ladder_start.push_back(from);
		queue.push(ladder_start);

		std::vector<std::string>::size_type min_path_length = 0;

		while (!queue.empty()) {
			std::vector<std::string> path = queue.front();
			queue.pop();

			// if the current considered path from the queue already
			// has a length greater than the size of the shortest path found
			// all short paths have been found, return all the paths found
			if (min_path_length > 0 && path.size() == min_path_length) {
				std::sort(paths_found.begin(), paths_found.end());
				return paths_found;
			}

			std::string word = path.back();

			// Loop through all letters of the given word,
			// and change letter one by one, and check if that is a valid
			// word in the lexicon
			for (std::string::size_type i = 0; i < word.length(); ++i) {
				for (char c = 'a'; c <= 'z'; ++c) {
					std::string word_replaced = word;
					word_replaced[i] = c;

					const std::unordered_set<std::string>::const_iterator found =
					   lexicon.find(word_replaced);

					// Word does not exist, continue loop
					if (found == lexicon.end()) {
						continue;
					}

					// Word is the destination word, path found
					if (*found == to) {
						std::vector<std::string> new_path = path;
						new_path.push_back(word_replaced);
						paths_found.push_back(new_path);
						// First path found will be the smallest path
						// set the size for the minimum path length
						if (min_path_length == 0) {
							min_path_length = new_path.size();
						}
					}

					// Valid word, create a new path to queue which has the
					// current word at the end, enqueue it
					if (found != lexicon.end()) {
						std::vector<std::string> new_path = path;
						new_path.push_back(word_replaced);
						std::vector<std::string>::size_type path_length = new_path.size();

						// Check if the distance to the current word exists, if there already
						// exist an entry in the distance_to_word map, that means there is a
						// shorter path to the given word, so continue the loop. Otherwise
						// create a new entry in the distance_to_word map with the distance
						// being the current path length
						if (distance_to_word.find(word_replaced) == distance_to_word.end()) {
							distance_to_word[word_replaced] = path_length;
						}
						else if (distance_to_word[word_replaced] < path_length) {
							continue;
						}

						queue.push(new_path);
					}
				}
			}
		}
		std::sort(paths_found.begin(), paths_found.end());
		return paths_found;
	}

} // namespace word_ladder