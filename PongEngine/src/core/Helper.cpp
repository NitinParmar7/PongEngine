#include "Helper.h"

#include <string>


ENGINE_BEGIN
    template <typename Derived, typename Base, typename Array, typename ... Args>
std::shared_ptr<Derived> Helper::AddObject(std::vector<std::shared_ptr<Array>> object_array, Args&&... args)
{
    static_assert(std::is_base_of_v<Base, Derived>);

    auto derived_object = std::make_shared<Derived>(std::forward<Args>(args)...);
    object_array.emplace_back(derived_object);
    return derived_object;
}

    template <typename Derived, typename Base, typename Array>
    bool Helper::RemoveObject(std::shared_ptr<Derived>& object, std::vector<std::shared_ptr<Array>> object_array)
    {
        static_assert(std::is_base_of_v<Base, Derived>);
        auto it = std::remove(object_array.begin(), object_array.end(), object);

        if(it != object_array.end())
        {
            object_array.erase(it, object_array.end());
            object.reset();
            return true;
        }
        else
        {
            return false;
        }
    }


ENGINE_END
