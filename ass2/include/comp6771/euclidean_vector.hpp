#ifndef COMP6771_EUCLIDEAN_VECTOR_HPP
#define COMP6771_EUCLIDEAN_VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace comp6771 {
	class euclidean_vector_error : public std::runtime_error {
	public:
		explicit euclidean_vector_error(std::string const& what)
		: std::runtime_error(what) {}
	};

	class euclidean_vector {
	public:
		// TODO
		euclidean_vector();
		explicit euclidean_vector(int dimensions);
		euclidean_vector(int dimensions, double magnitude);
		euclidean_vector(std::initializer_list<double> v);
		euclidean_vector(std::vector<double>::const_iterator b, std::vector<double>::const_iterator e);
		euclidean_vector(euclidean_vector const& v);  
		euclidean_vector(euclidean_vector const&& v); 	
	private:
		// ass2 spec requires we use std::unique_ptr<double[]>
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		std::unique_ptr<double[]> magnitude_;
		// TODO more if needed
		std::size_t size_;
	};
} // namespace comp6771
#endif // COMP6771_EUCLIDEAN_VECTOR_HPP
