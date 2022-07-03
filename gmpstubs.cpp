
/*
Make functions that take in strings and output strings.
We _could_ use pointers for interemedate states, but whatever. We should be interning anyway.
Probably it is desirable to memoize

At souffle level
@gmp_to_string(gmp_add(@gmp_from_string(x), @gmp_from_string(y)))

Or maybe just do it here. It's safer.

#define souffleunary
@define SOUFBIN 

SOUFBIN(gmp_add)
SOUFBIN(gmp_sub)
etc.

Maybe i could use constexpr? Or lambdas? Just for fun?

The memory management is taken care of in the most conservatie way. We immediately destroy all values.

constexpr soufflebinop(f){
    [](table,table,x,y){
        x1 = gmp_from_string(decode(x))
        y1 = 
        z1 = f(x1,y1);
        z = encode(z1)
        free(x1,y1,z1)
        return z
    }
}


from_float(str)
to_float(str)
gmp_int gmp_from_string(souffle:table, arg1){

}
gmp_to_string( , arg1) // Hmm. Is it gonna bit us?

*/
#include <gmp.h>
#include <iostream>




extern "C" {

    // We're probably leaking memory associated with the strings.
    const char* mpqs_of_float(float x){
        mpq_t y;
        mpq_init(y);
        mpq_set_d(y, x);
        char* res = mpq_get_str(NULL,10,y);
        mpq_clear(y);
        if(res == NULL){
            return "NULL";
        }
        return res;
    }
    float float_of_mpqs(const char* x){
        mpq_t x1;
        mpq_init(x1);
        mpq_set_str(x1,x,10);
        double z = mpq_get_d(x1);
        mpq_clear(x1);
        return (float) z;
    }

    const char* mpqs_of_double(double x){
        mpq_t y;
        mpq_init(y);
        mpq_set_d(y, x);
        char* res = mpq_get_str(NULL,10,y);
        mpq_clear(y);
        if(res == NULL){
            return "NULL";
        }
        return res;
    }
    float double_of_mpqs(const char* x){
        mpq_t x1;
        mpq_init(x1);
        mpq_set_str(x1,x,10);
        double z = mpq_get_d(x1);
        mpq_clear(x1);
        return z;
    }
    const char* mpqs_add(const char* x, const char* y){
        mpq_t x1, y1, z1;
        mpq_init(x1);
        mpq_init(y1);
        mpq_init(z1);
        mpq_set_str(x1,x,10);
        mpq_set_str(y1,y,10);

        mpq_add(z1, x1, y1);

        char* res = mpq_get_str(NULL,10,z1);
        mpq_clear(x1);
        mpq_clear(y1);
        mpq_clear(z1);
        return res;
    }

        const char* mpqs_sub(const char* x, const char* y){
        mpq_t x1, y1, z1;
        mpq_init(x1);
        mpq_init(y1);
        mpq_init(z1);
        mpq_set_str(x1,x,10);
        mpq_set_str(y1,y,10);

        mpq_sub(z1, x1, y1);

        char* res = mpq_get_str(NULL,10,z1);
        mpq_clear(x1);
        mpq_clear(y1);
        mpq_clear(z1);
        return res;
    }

    const char* mpqs_mul(const char* x, const char* y){
        mpq_t x1, y1, z1;
        mpq_init(x1);
        mpq_init(y1);
        mpq_init(z1);
        mpq_set_str(x1,x,10);
        mpq_set_str(y1,y,10);

        mpq_mul(z1, x1, y1);

        char* res = mpq_get_str(NULL,10,z1);
        mpq_clear(x1);
        mpq_clear(y1);
        mpq_clear(z1);
        return res;
    }
    const char* mpqs_div(const char* x, const char* y){
        mpq_t x1, y1, z1;
        mpq_init(x1);
        mpq_init(y1);
        mpq_init(z1);
        mpq_set_str(x1,x,10);
        mpq_set_str(y1,y,10);

        mpq_mul(z1, x1, y1);

        char* res = mpq_get_str(NULL,10,z1);
        mpq_clear(x1);
        mpq_clear(y1);
        mpq_clear(z1);
        return res;
    }
    const char* mpqs_abs(const char* x){
        mpq_t x1, z1;
        mpq_init(x1);
        mpq_init(z1);
        mpq_set_str(x1,x,10);

        mpq_abs(z1, x1);

        char* res = mpq_get_str(NULL,10,z1);
        mpq_clear(x1);
        mpq_clear(z1);
        return res;
    }
    const char* mpqs_neg(const char* x){
        mpq_t x1, z1;
        mpq_init(x1);
        mpq_init(z1);
        mpq_set_str(x1,x,10);

        mpq_abs(z1, x1);

        char* res = mpq_get_str(NULL,10,z1);
        mpq_clear(x1);
        mpq_clear(z1);
        return res;
    }

    const char* mpqs_inv(const char* x){
        mpq_t x1, z1;
        mpq_init(x1);
        mpq_init(z1);
        mpq_set_str(x1,x,10);

        mpq_abs(z1, x1);

        char* res = mpq_get_str(NULL,10,z1);
        mpq_clear(x1);
        mpq_clear(z1);
        return res;
    }


    int32_t mpqs_cmp(const char* x, const char* y){
        mpq_t x1, y1;
        mpq_init(x1);
        mpq_init(y1);
        mpq_set_str(x1,x,10);
        mpq_set_str(y1,y,10);

        int z = mpq_cmp(x1, y1);

        mpq_clear(x1);
        mpq_clear(y1);
        return z;
    }

}


