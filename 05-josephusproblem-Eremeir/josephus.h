#ifndef H_JOSEPHUS
#define H_JOSEPHUS

#include <string>

#define NO_LETS  26    // no of letters in English alphabet

/**
* A class that may be used as a generator to assign IDs/names
* For the Josephus problem.
*****************************************************************************/
class SEQ
{
private:
    std::string id;     ///< name tag for person
    unsigned size;      ///< no of people (spec'd by constructor)
    unsigned nd;        ///< no of characters needed in the name tags

    /**
    * Calculate a log base-26 of the given number.
    * This value represents how manay characters are needed
    * for the generated names.
    *
    * @param sz The number if IDs that need to be generated.
    * @return The character length needed for sz number of names.
    *************************************************************************/
    unsigned find_nd(const double& sz) 
    {
        if ((sz/NO_LETS) <= 1)
            return 1;
        else 
            return(find_nd(sz/NO_LETS)+1);      // calculate the value recursively
    }

public:
    /**
    * Constructor
    *
    * @param s The total number of names that are expected to be generated.
    *************************************************************************/
    SEQ(const unsigned& s=1) : size(s)
    {
        nd = find_nd(s);            // figure out how many chars we need to use
        id = std::string(nd, 'A');  // prime the ID with the first tag name 
    }

    /**
    * @return The value of the next name tag in sequence.
    *************************************************************************/
    std::string operator()()
    {
        auto tmp = id;      // copy the current value to be returned
        bool done = true;   // used to signal when we are done adding

        // Increment the ID name for the next call 
        for (int i=nd-1; i >= 0 && done; --i)
        {
            if (id[i] < 'Z') 
            {
                // If letter is not a Z then we can advance it and be done
                ++id[i];    
                done = false; 
            }
            else 
            {
                // If letter is Z then go back to with a carry into next position 
                id[i] = 'A';
            }
        }
        return tmp;
    }
};

#endif
