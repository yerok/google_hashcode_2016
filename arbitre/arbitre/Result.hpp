#pragma once

#include <string>
#include <vector>
#include <iostream>




class Result {

friend std::ostream& operator<<(std::ostream&, const Result&);

private:
	std::string m_input;
	std::string m_output;
	unsigned int m_time;

	long m_number_of_pictures;

	struct execution_result{
		unsigned int m_score;
		long m_latitude;
		long m_longitude;
		unsigned short m_id_satellite;
		unsigned int m_moment;
	};

	struct less_than_key
	{
	    inline bool operator() (const execution_result& struct1, const execution_result& struct2)
	    {
	        return (struct1.m_id_satellite < struct2.m_id_satellite);
	    }
	};

	std::vector<execution_result> m_results;
public:
	Result() {};
	Result(std::string m_input, std::string m_output, unsigned int m_time);

	// TODO
	unsigned int FigureOutScore(std::string &input_file);

	// TODO verifier le parsing.
	void parse(std::string &);
};

