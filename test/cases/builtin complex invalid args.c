void foo(void *p, _Complex double z, _Atomic double ad) {
    _Complex double a = __builtin_complex(p, p);
    _Complex double b = __builtin_complex(z, z);
    _Complex double c = __builtin_complex(1.0, p);
    _Complex double d = __builtin_complex(ad, ad);

    __fp16 h = 1.0;
    _Complex double e = __builtin_complex(h, h);
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu

builtin complex invalid args.c:2:43: error: argument type 'void *' is not a real floating point type
builtin complex invalid args.c:2:46: error: argument type 'void *' is not a real floating point type
builtin complex invalid args.c:3:43: error: argument type '_Complex double' is not a real floating point type
builtin complex invalid args.c:3:46: error: argument type '_Complex double' is not a real floating point type
builtin complex invalid args.c:4:48: error: argument type 'void *' is not a real floating point type
builtin complex invalid args.c:8:43: error: '_Complex __fp16' is invalid
builtin complex invalid args.c:8:46: error: '_Complex __fp16' is invalid
*/
