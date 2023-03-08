// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include <comp6771/euclidean_vector.hpp>

namespace comp6771 {
	// Implement solution here
	euclidean_vector::euclidean_vector() {
		magnitude_ = std::make_unique<double[]>(1);
		magnitude_[0] = 0.0;
		size_ = 1;
	}

	euclidean_vector::euclidean_vector(int dimensions) {
		size_ = static_cast<std::size_t>(dimensions);
		magnitude_ = std::make_unique<double[]>(size_);
		for (std::size_t i = 0; i < size_; ++i) {
			magnitude_[i] = 0.0;
		}


 	}

	euclidean_vector::euclidean_vector(int dimensions, double magnitude) {
		size_ = static_cast<std::size_t>(dimensions);
		magnitude_ = std::make_unique<double[]>(size_);
		for (unsigned int i = 0; i < static_cast<unsigned int>(dimensions); ++i) {
			magnitude_[i] = magnitude;
		}
	}

	euclidean_vector::euclidean_vector(std::initializer_list<double> v) {
		magnitude_ = std::make_unique<double[]>(static_cast<unsigned int>(v.size()));
		std::size_t i = 0;
		for (auto magnitude : v) {
			magnitude_[i] = magnitude;
			++i;
		}
		size_ = v.size();
	}

	// TODO iterator vector constructor
	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator b, std::vector<double>::const_iterator e) {
		
	}

	euclidean_vector::euclidean_vector(euclidean_vector const& v) :
		size_{v.size_} {
		magnitude_ = std::make_unique<double[]>(static_cast<unsigned int>(v.size_));
		for (std::size_t i = 0; i < v.size_; ++i) {
			magnitude_[i] = v.magnitude_[i];
		}
	}

	euclidean_vector::euclidean_vector(euclidean_vector const&& v) : 
		size_{std::move(v.size_)} {
		
		auto begin = v.magnitude_.get();
		std::move(begin, std::next(begin, static_cast<long>(v.size_)), magnitude_.get());
		
	}


} // namespace comp6771
