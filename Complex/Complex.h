#pragma once
#ifndef _COMPLEX_NUMS
#define _COMPLEX_NUMS
#include <string>
#include <sstream>
#include <istream>

template<typename T> struct complex{
public:
	typedef T real;
	typedef T imag;
	real a;
	imag b;
	complex(void){
		(*this).a = 0;
		(*this).b = 0;
	}
	complex(real a){
		(*this).a = a;
		(*this).b = 0;
	}
	complex(real a, imag b){
		(*this).a = a;
		(*this).b = b;
	}
	operator std::string(void){
		std::stringstream temp;
		temp<<this->a;
		if(this->b!=0)
		{
			if(this->b>0)
			{
				temp<<"+";
			}
			if(this->b!=1)
			{
				temp<<this->b;
			}
			temp<<"i";
		}
		return temp.str();
	}
	complex getConjugate(void){
		return complex(this->a, -this->b);
	}
	void operator = (real value){
		*this = complex(value,0);
	}
	complex operator + (real add){
		return complex(this->a+add,this->b);
	}
	complex operator + (complex that){
		return complex(this->a + that.a, this->b + that.b);
	}
/*	complex operator + (real start,complex sum)
	{
		return complex(start+sum.a,sum.b);
	}*/
	void operator += (real diff){
		*this = complex(this->a + diff,this->b);
	}
	void operator += (complex that){
		*this = complex(this->a + that.a,this->b - that.b);
	}
	void operator ++ (void){
		*this = complex(this->a+1,this->b);
	}
	complex operator - (real diff){
		return complex(this->a-diff,this->b);
	}
	complex operator - (complex that){
		return complex(this->a - that.a, this->b - that.b);
	}
/*	complex operator - (real start,complex diff)
	{
		return complex(start-diff.a,diff.b);
	}*/
	void operator -= (real diff){
		*this = complex(this->a - diff,this->b);
	}
	void operator -= (complex that){
		*this = complex(this->a - that.a,this->b - that.b);
	}
	void operator -- (void){
		*this = complex(this->a-1,this->b);
	}
	complex operator * (real factor){
		return complex(this->a * factor, this->b * factor);
	}
	complex operator * (complex that){
		return complex(this->a * that.a - this->b * that.b, this->a * that.b + this->b * that.a);
	}
/*	complex operator * (real start,complex factor)
	{
		return complex(start*factor.a,start*factor.b);
	}*/
	void operator *= (real factor){
		*this = complex(this->a * factor, this->b * factor);
	}
	void operator *= (complex that){
		*this = complex(this->a * that.a - this->b * that.b, this->a * that.b + this->b * that.a);
	}
	complex operator / (real divisor){
		return complex(this->a / divisor, this->b / divisor);
	}
	complex operator / (complex that){
		return complex(*this * that.getConjugate()) / (that.a * that.a + that.b * that.b);
	}
/*	complex operator / (real start,complex divisor)
	{
		return complex(start/divisor.a,start/divisor.b);
	}*/
	void operator /= (real factor){
		*this = complex(this->a / divisor, this->b / divisor);
	}
	void operator /= (complex that){
		*this = complex(*this * that.getConjugate()) / (that.a * that.a + that.b * that.b);
	}
	bool operator == (complex that){
		return (this->a==that.a&&this->b==that.b);
	}
	bool operator != (complex that){
		return (this->a!=that.a||this->b!=that.b);
	}
/*	bool operator === (complex that){
		return (this->a===that.a&&this->b===that.b);
	}*/
/*	complex operator << (complex that){
		*this = complex(that.a,that.b);
	}
	complex operator >> (complex that){
		std::string input;
		std::cin>>input;
		if(input.find("+"!=std::string::npos){
			input.split("+");
		}else if(input.find("-"!=std::string::npos){
			input.split("-");
		}else{
			*this = complex(numFncs.input
		}
		*this = complex(that.a,that.b);
	}
*/
};
/*complex<T> operator * (int lhs,complex<T> rhs){
	return complex<T>(lhs*rhs->a, lhs*rhs->b);
}*/
#endif