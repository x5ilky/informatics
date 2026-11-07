// Silky TL Debug header
//
// Usage:
//   To see debug messages, define the macro DEBUG:
//     - either by #define DEBUG
//     - or by using flag -DDEBUG during compilation
//   Either include this file and use a file expander, or just paste
//     this file at the top of your code.
//   To print out messages, use `dbg::print()` or `dbt::println()`.
//   This header AUTOMATICALLY INCLUDES <bits/stdc++.h>!!!!
//
// `dbg::print()`: !! ALWAYS PRINTS !!
//   Each variable should have {} in place of its position.
//   e.g. dbg::print("x = {}\n", x);
// `dcheck(<expr>)`: <debug only>
//   dcheck prints a message in the format `<expr> = <value of expr>`.
//   e.g. dcheck(x + 3) prints `x + 3 = 67`.
// `dprint()`: <debug only>
//   The same as dbg::print, however only enabled with -DDEBUG
//

#ifndef _SILKY_DEBUG 
#define _SILKY_DEBUG
#include <bits/stdc++.h>

#define sRESET   "\033[0m"
#define sBLACK   "\033[30m"
#define sRED     "\033[31m"
#define sGREEN   "\033[32m"
#define sYELLOW  "\033[33m"
#define sBLUE    "\033[34m"
#define sMAGENTA "\033[35m"
#define sCYAN    "\033[36m"
#define sWHITE   "\033[37m"

#define sGRAY    "\033[90m"
#define sBRED    "\033[91m"
#define sBGREEN  "\033[92m"
#define sBYELLOW "\033[93m"
#define sBBLUE   "\033[94m"
#define sBMAGENTA "\033[95m"
#define sBCYAN   "\033[96m"
#define sBWHITE  "\033[97m"

#define sBOLD    "\033[1m"
#define sDIM     "\033[2m"
#define sITALIC  "\033[3m"
#define sUNDER   "\033[4m"
#define sSTRIKE  "\033[9m"
template<class T>
struct is_string_like : std::false_type {};

template<>
struct is_string_like<std::string> : std::true_type {};

template<>
struct is_string_like<char*> : std::true_type {};

template<>
struct is_string_like<const char*> : std::true_type {};

template<std::size_t N>
struct is_string_like<char[N]> : std::true_type {};

template<std::size_t N>
struct is_string_like<const char[N]> : std::true_type {};

template<class T>
struct is_iterable {
    template<class U>
    static auto test(int) -> decltype(
        std::begin(std::declval<const U&>()),
        std::end(std::declval<const U&>()),
        std::true_type{}
    );

    template<class>
    static std::false_type test(...);

    static const bool value = decltype(test<T>(0))::value;
};


template<class T>
struct is_vector {
private:
    template<class U, class Alloc>
    static std::true_type test(const std::vector<U, Alloc>*);

    static std::false_type test(...);

public:
    static constexpr bool value =
        decltype(test(std::declval<
            const typename std::decay<T>::type*
        >()))::value;
};

template<class T, class = void>
struct is_integer_vector : std::false_type {};

template<class T>
struct is_integer_vector<T,
    typename std::enable_if<is_vector<T>::value>::type
> : std::integral_constant<bool,
    std::is_integral<
        typename std::decay<T>::type::value_type
    >::value &&
    !std::is_same<
        typename std::decay<T>::type::value_type, bool
    >::value
> {};

template<class T>
struct is_nested_vector {
    using element_type = typename std::decay<
        decltype(*std::begin(std::declval<const T&>()))
    >::type;

    static constexpr bool value =
        is_iterable<element_type>::value &&
        !is_string_like<element_type>::value;

    using type = std::integral_constant<bool, value>;
};


template<class A, class B>
std::ostream& operator<<(std::ostream&, const std::pair<A, B>&);

template<class... Ts>
std::ostream& operator<<(std::ostream&, const std::tuple<Ts...>&);

template<class T>
typename std::enable_if<
    is_iterable<T>::value &&
    !is_string_like<typename std::decay<T>::type>::value,
    std::ostream&
>::type operator<<(std::ostream&, const T&);

namespace pretty {

    inline int depth_slot() {
        static int slot = std::ios_base::xalloc();
        return slot;
    }

    struct depth_guard {
        std::ostream& os;
        int depth;

        explicit depth_guard(std::ostream& stream)
            : os(stream), depth(static_cast<int>(
                stream.iword(depth_slot()))) {
            ++os.iword(depth_slot());
        }

        ~depth_guard() {
            --os.iword(depth_slot());
        }
    };

    inline const char* color(int depth) {
        static const char* colors[] = {
            sCYAN, sYELLOW, sMAGENTA,
            sBLUE, sGREEN, sRED
        };
        return colors[depth % 6];
    }

    inline void bracket(std::ostream& os, char c, int depth) {
        os << color(depth) << c << sRESET;
    }

    inline void indent(std::ostream& os, int depth) {
        os << std::string(depth * 2, ' ');
    }

    template<class T>
    void element(std::ostream& os, const T& x,
                 bool first, std::true_type) {
        if (first && x == 0)
            os << sGRAY << x << sRESET;
        else
            os << x;
    }

    template<class T>
    void element(std::ostream& os, const T& x,
                 bool, std::false_type) {
        os << x;
    }

    template<class Container>
    void elements(std::ostream& os, const Container& v,
                  std::false_type) {
        bool first = true;
        for (const auto& x : v) {
            if (!first)
                os << sGRAY ", " sRESET;
            element(os, x, first, typename is_integer_vector<
                typename std::decay<Container>::type
            >::type{});

            first = false;
        }
    }

    template<class Container>
    void elements(std::ostream& os, const Container& v,
                  std::true_type) {
        bool first = true;
        for (const auto& x : v) {
            if (!first)
                os << sGRAY "," sRESET;
            os << '\n';
            indent(os, static_cast<int>(os.iword(depth_slot())));
            os << x;

            first = false;
        }
        if (!first) {
            os << '\n';
            indent(os, static_cast<int>(os.iword(depth_slot())) - 1);
        }
    }
    template<std::size_t I, class... Ts>
    typename std::enable_if<I == sizeof...(Ts), void>::type
    tuple_elements(std::ostream&, const std::tuple<Ts...>&) {}
    template<std::size_t I, class... Ts>
    typename std::enable_if<I < sizeof...(Ts), void>::type
    tuple_elements(std::ostream& os, const std::tuple<Ts...>& t) {
        if (I)
            os << sGRAY ", " sRESET;
        os << std::get<I>(t);
        tuple_elements<I + 1>(os, t);
    }
}

template<class A, class B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& p) {
    pretty::depth_guard guard(os);

    pretty::bracket(os, '(', guard.depth);
    os << p.first << sGRAY ", " sRESET << p.second;
    pretty::bracket(os, ')', guard.depth);

    return os;
}

template<class... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
    pretty::depth_guard guard(os);

    pretty::bracket(os, '<', guard.depth);
    pretty::tuple_elements<0>(os, t);
    pretty::bracket(os, '>', guard.depth);

    return os;
}

template<class T>
typename std::enable_if<
    is_iterable<T>::value &&
    !is_string_like<typename std::decay<T>::type>::value,
    std::ostream&
>::type operator<<(std::ostream& os, const T& v) {
    pretty::depth_guard guard(os);

    pretty::bracket(os, '[', guard.depth);

    pretty::elements(os, v, typename is_nested_vector<
        typename std::decay<T>::type
    >::type{});

    pretty::bracket(os, ']', guard.depth);
    return os;
}

namespace dbg {
    inline void format(std::ostream& os, const std::string& fmt) {
        os << fmt;
    }
    template<class T, class... Rest>
    void format(std::ostream& os, const std::string& fmt,
                const T& value, const Rest&... rest) {
        std::size_t pos = fmt.find("{}");

        if (pos == std::string::npos)
            throw std::runtime_error("too many format arguments");

        os << fmt.substr(0, pos) << value;
        format(os, fmt.substr(pos + 2), rest...);
    }
    template<class... Args>
    void print(std::ostream& os, const std::string& fmt,
               const Args&... args) {
        format(os, fmt, args...);
    }

    template<class... Args>
    void println(std::ostream& os, const std::string& fmt,
                 const Args&... args) {
        format(os, fmt, args...);
        os << '\n';
    }

    template<class... Args>
    void print(const std::string& fmt, const Args&... args) {
        print(std::cerr, fmt, args...);
    }

    template<class... Args>
    void println(const std::string& fmt, const Args&... args) {
        println(std::cerr, fmt, args...);
    }
}
#endif//_SILKY_DEBUG_HPP 
