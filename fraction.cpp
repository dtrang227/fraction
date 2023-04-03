#include <iostream>


template <class T>
class Fraction
{
    private:
        T numerator, denominator;
    
    public:
        //constructor
        Fraction(T num = 0, T deno = 1)
        {
            this->numerator = num;
            this->denominator = deno;
        };

        //copy constructor
        Fraction(const Fraction &frac)
        {
            this->numerator = frac.numerator;
            this->denominator = frac.denominator;
        };

        //assignment constructor
        void operator=(const Fraction &term)
        {
            this->numerator = term.numerator;
            this->denominator = term.denominator;
        }

        //add func
        Fraction add(const Fraction &term);
        // {
        //     // Fraction temp;
        //     // temp.numerator = (this->numerator * term.denominator) + (term.numerator * this->denominator);
        //     // temp.denominator = this->denominator * term.denominator;
        //     // return temp;
        // };

        //sub func
        Fraction sub(const Fraction &term)
        {
            T numer = (this->numerator * term.denominator) - (term.numerator * this->denominator);
            T denomi = this->denominator * term.denominator;
            return Fraction<T>(numer,denomi);
        };

        //multiple func
        Fraction multiple(const Fraction &term)
        {
            Fraction temp;
            temp.numerator = this->numerator * term.numerator;
            temp.denominator = this->denominator * term.denominator;
            return temp;
        };

        //divide func
        Fraction divide(const Fraction &term)
        {
            Fraction temp;
            temp.numerator = this->numerator * term.denominator;
            temp.denominator = this->denominator * term.numerator;
            return temp;
        };

        //simplify
        void simplify(void)
        {
            
        }


        //compare
        int compare(const Fraction &term)
        {
            if (this->denominator == term.denominator)
            {
                if (this->numerator > term.numerator)
                {
                    return 1;
                }
                else if ( this->numerator == term.numerator)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if ((this->numerator * term.denominator) > (term.numerator * this->denominator))
                {
                    return 1;
                }
                else if ((this->numerator * term.denominator) == (term.numerator * this->denominator))
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
        };

        //operator+
        Fraction operator+(const Fraction &term)
        {
            T n = (this->numerator * term.denominator) + (term.numerator * this->denominator);
            T d = this->denominator * term.denominator;
            return Fraction<T>(n, d);
        };

        //operator-
        Fraction operator-(const Fraction &term)
        {
            T n = (this->numerator * term.denominator) - (term.numerator * this->denominator);
            T d = this->denominator * term.denominator;
            return Fraction<T>(n, d);
        };

        Fraction operator+=(const Fraction &term)
        {
            this->numerator = this->numerator + term.numerator;
            this->denominator = this->denominator + term.denominator;
            return *this;
        };

        //operator++
        Fraction& operator++()
        {
            this->numerator = this->numerator + this->denominator;
            return *this;
        };


        Fraction operator++(int)
        {
            Fraction temp = *this;
            this->numerator = this->numerator + this->denominator;
            return temp;
        };

        // bool operator>=(Fraction temp)
        // {
        //     if ()
        //     {
                
        //     }
        //     else
        //     {
        //         return false;
        //     }
            
        // };

        // void FructionPrint()
        // {
        //     cout << numerator << "/" << denominator << endl;
        // };

        friend std::ostream& operator<<(std::ostream &out, const Fraction &temp)
        {
            out << temp.numerator << "/" << temp.denominator << std::endl;
            return out;
        }

        friend std::istream& operator>>(std::istream &in, Fraction &temp)
        {
            std::cout << "tu so:" << std::endl;
            in >> temp.numerator;
            std::cout << "mau so:" << std::endl;
            in >> temp.denominator;
            return in;
        }


};
template <class T>
Fraction<T> Fraction<T>::add(const Fraction &term)
{
    Fraction temp;
            temp.numerator = (this->numerator * term.denominator) + (term.numerator * this->denominator);
            temp.denominator = this->denominator * term.denominator;
            return temp;
    }

int main()
{
    Fraction <int> frac2;
    Fraction <int> frac3 (5,4);
    Fraction <int> frac1 (1,4);
    
    frac2 = frac3.add(frac1);
    // std::cin >> frac2;
    std::cout << frac2 << std::endl;
    // frac2.FructionPrint();
    return 0;
}