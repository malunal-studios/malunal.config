/// @file stdafx.hpp
/// @brief Contains the headers to precompile, if possible.
/// @author John Christman sorakatadzuma@gmail.com
/// @copyright 2024 Malunal Studios, LLC.
#pragma once
#include <algorithm>
#include <array>
#include <concepts>
#include <cstdint>
#include <expected>
#include <fstream>
#include <functional>
#include <map>
#include <memory>
#include <memory_resource>
#include <mutex>
#include <optional>
#include <set>
#include <span>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <thread>
#include <type_traits>
#include <utility>
#include <variant>


namespace malunal {

using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::size_t;
using std::ptrdiff_t;

/// @brief   Alias consistent with other commonly used typedefs.
/// @details The name for this is chosen because it also more closely aligns
///          with the naming of the other type definitions, in comparison to
///          the default keywords.
using float32_t = float;

/// @brief   Alias consistent with other commonly used typedefs.
/// @details The name for this is chosen because it also more closely aligns
///          with the naming of the other type definitions, in comparison to
///          the default keywords.
using float64_t = double;

/// @brief   Standard library error code alias.
/// @details Commonly used, matches the style of the other aliases.
using error_t = std::error_code;

/// @brief   Standard library error category alias.
/// @details Used sometimes, matches the style of the other aliases.
using errcat_t = std::error_category;

/// @brief   C-style raw pointer alias.
/// @details Added for more consistency when working with interchangeable
///          pointers types like: `std::unique_ptr` and `std::shared_ptr`.
using crptr_t = void*;

/// @brief   Standard library mutex alias.
/// @details Used sometimes, matches the style of the other aliases.
using mutex_t = std::mutex;

/// @brief   Standard library out-string stream alias.
/// @details Used sometimes, matches the style of the other aliases.
using strbuf_t = std::ostringstream;

/// @brief   C-style string alias.
/// @details Added for more consistency when working with interchangable string
///          types like `std::string` and `std::string_view`.
using cstring_t = char*;

/// @brief   Standard library string alias.
/// @details Commonly used, matches the style of the other aliases.
using string_t = std::string;

/// @brief   Standard library string view alias.
/// @details Commonly used, matches the style of the other aliases.
using strview_t = std::string_view;

/// @brief   Standard library thread alias.
/// @details Used sometimes, matches the style of the other aliases.
using thread_t = std::thread;


/// @brief   Standard library array alias.
/// @details Commonly used, matches the style of the other aliases.
/// @tparam  TValue The type of the values stored in the array.
/// @tparam  KSize  The number of elements stored in the array.
template<typename TValue, size_t KSize>
using array_t = std::array<TValue, KSize>;

/// @brief   Standard library expected alias.
/// @details This is a heavily used alias, as we try to avoid using exceptions
///          within our code base. Not because it's more performant, although it
///          may have negligible margins, but for the fact that we want to
///          represent an potential issue and handle it immediately. If the
///          error should propagate, it will do so naturally.
/// @tparam  TValue The type of the value expected to be the result.
template<typename TValue>
using result_t = std::expected<TValue, error_t>;

/// @brief   Standard library map alias.
/// @details Used rarely, matches the style of the other aliases. Name was
///          chosen based on the fact that dictionaries are alphabetically
///          ordered, and the standard map is ordered.
/// @tparam  TKey   The type of key stored in the map.
/// @tparam  TValue The type of value stored in the map.
template<typename TKey, typename TValue>
using dict_t = std::pmr::map<TKey, TValue>;

/// @brief   Standard library unordered map alias.
/// @details Used sometimes, matches the style of the other aliases. Name was
///          chosen based on the fact that mappings are unordered, just like
///          the container being aliased, unlike `std::map`.
/// @tparam  TKey   The type of key stored in the map.
/// @tparam  TValue The type of value stored in the map.
template<typename TKey, typename TValue>
using map_t = std::pmr::unordered_map<TKey, TValue>;

/// @brief   Standard library unique pointer alias.
/// @details Used sometimes, matches the style of the other aliases. Name was
///          chosen based on the fact that the caller receiving the pointer is
///          the owner of that pointer.
/// @tparam  TValue The type of data stored at the pointer.
template<typename TValue>
using owner_t = std::unique_ptr<TValue>;

/// @brief   Standard library shared pointer alias.
/// @details Used sometimes, matches the style of the other aliases. Name was
///          chosen based on the fact that the caller receiving the pointer is
///          sharing that pointer.
/// @tparam TValue 
template<typename TValue>
using shared_t = std::shared_ptr<TValue>;

/// @brief   Standard library lock guard alias.
/// @details Used sometimes, matches the style of the other aliases. Name was
///          chosen based on the fact that it guards execution of a function.
/// @tparam  TMutex The type of mutex given to the lock guard.
template<typename TMutex>
using guard_t = std::lock_guard<TMutex>;

/// @brief   Standard library optional alias.
/// @details Used sometimes, matches the style of the other aliases.
/// @tparam  TValue The type of value stored in the optional.
template<typename TValue>
using opt_t = std::optional<TValue>;

/// @brief   Standard library set alias.
/// @details Used rarely, matches the style of the other aliases. Name was
///          chosen because it's ordered and there is no `set` equivalent of
///          the logic that was applied to `std::map` and `std::unordered_map`.
/// @tparam  TValue The type of value stored in the ordered set.
template<typename TValue>
using oset_t = std::pmr::set<TValue>;

/// @brief   Standard library unordered set alias.
/// @details Used sometimes, matches the style of the other aliases. Name was
///          chosen based on the fact that sets are unordered, just like the
///          container being aliased, unlike `std::set`.
/// @tparam  TValue The type of value stored in the unordered set.
template<typename TValue>
using set_t = std::pmr::unordered_set<TValue>;

/// @brief   Standard library span alias.
/// @details Used rarely, matches the style of the other aliases.
/// @tparam  TContainer The type of the container the span operates on.
/// @tparam  KExtent    The number of elements that the span covers.
template<typename TContainer, size_t KExtent = std::dynamic_extent>
using span_t = std::span<TContainer, KExtent>;

/// @brief   Standard library vector alias.
/// @details Commonly used, matches the style of the other aliases.
/// @tparam  TValue The type of value being stored.
template<typename TValue>
using vec_t = std::pmr::vector<TValue>;

/// @brief   Standard library pair alias.
/// @details Used rarely, matches the style of the other aliases.
/// @tparam  TFirst  The type of the first value in the pair.
/// @tparam  TSecond The type of the second value in the pair.
template<typename TFirst, typename TSecond>
using pair_t = std::pair<TFirst, TSecond>;

/// @brief   Standard library tuple alias.
/// @details Used rarely, matches the style of the other aliases.
/// @tparam  ...TValues The types of the values stored in the tuple.
template<typename... TValues>
using tuple_t = std::tuple<TValues...>;

/// @brief   Standard library variant alias.
/// @details Used sometimes, matches the style of the other aliases. Name was
///          chosen because it is effectively a discriminated union.
/// @tparam  ...TValues The types that the value, stored in the variant, may be.
template<typename... TValues>
using union_t = std::variant<TValues...>;


} // namespace malunal
