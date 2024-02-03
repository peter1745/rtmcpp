#pragma once

#include "Core.hpp"

#if !defined(RTMCPP_BUILD_MODULE)
	#include <rtm/math.h>
	#include <rtm/vector4f.h>
	#include <rtm/vector4d.h>
#endif

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType, size_t ComponentCount>
	struct Vector
	{
		using ValueType = std::conditional_t<std::is_same_v<ComponentType, float>, rtm::vector4f, rtm::vector4d>;
		using ScalarType = std::conditional_t<std::is_same_v<ComponentType, float>, rtm::scalarf, rtm::scalard>;

		union
		{
			ValueType Value;

			struct
			{
				ComponentType X;
				ComponentType Y;
				ComponentType Z;
				ComponentType W;
			};
		};

		Vector() noexcept
			: Value(rtm::vector_zero())
		{
		}

		Vector(const ValueType& value) noexcept
			: Value(value)
		{
		}

		Vector(ComponentType x, ComponentType y) noexcept
		{
			Value = rtm::vector_set(x, y, ComponentType(0), ComponentType(0));
		}

		Vector(ComponentType x, ComponentType y, ComponentType z) noexcept requires(ComponentCount >= 3)
		{
			Value = rtm::vector_set(x, y, z, ComponentType(0));
		}

		Vector(ComponentType x, ComponentType y, ComponentType z, ComponentType w) noexcept requires(ComponentCount == 4)
		{
			Value = rtm::vector_set(x, y, z, w);
		}

		Vector(const Vector<ComponentType, 2>& xy, ComponentType z) noexcept requires(ComponentCount == 3)
		{
			Value = rtm::vector_set(xy.X, xy.Y, z, ComponentType(0));
		}

		Vector(const Vector<ComponentType, 3>& xyz, ComponentType w) noexcept requires(ComponentCount == 4)
		{
			Value = rtm::vector_set(xyz.X, xyz.Y, xyz.Z, w);
		}

		Vector(const Vector& other) noexcept
			: Value(rtm::vector_set(other.X, other.Y, other.Z, other.W))
		{
		}

		Vector& RTMCPP_VECTOR_CALL operator+=(const Vector& other) noexcept
		{
			Value = rtm::vector_add(Value, other.Value);
			return *this;
		}

		Vector& RTMCPP_VECTOR_CALL operator-=(const Vector& other) noexcept
		{
			Value = rtm::vector_sub(Value, other.Value);
			return *this;
		}

		Vector& RTMCPP_VECTOR_CALL operator*=(const Vector& other) noexcept
		{
			Value = rtm::vector_mul(Value, other.Value);
			return *this;
		}

		Vector& RTMCPP_VECTOR_CALL operator/=(const Vector& other) noexcept
		{
			Value = rtm::vector_div(Value, other.Value);
			return *this;
		}

		Vector RTMCPP_VECTOR_CALL operator+(const Vector& other) const noexcept
		{
			Vector result;
			result.Value = rtm::vector_add(Value, other.Value);
			return result;
		}

		Vector RTMCPP_VECTOR_CALL operator-(const Vector& other) const noexcept
		{
			Vector result;
			result.Value = rtm::vector_sub(Value, other.Value);
			return result;
		}

		Vector RTMCPP_VECTOR_CALL operator*(const Vector& other) const noexcept
		{
			Vector result;
			result.Value = rtm::vector_mul(Value, other.Value);
			return result;
		}

		Vector RTMCPP_VECTOR_CALL operator/(const Vector& other) const noexcept
		{
			Vector result;
			result.Value = rtm::vector_div(Value, other.Value);
			return result;
		}

		ComponentType RTMCPP_VECTOR_CALL Length() const
		{
			if constexpr (ComponentCount == 2)
			{
				ScalarType lengthSq = rtm::vector_length_squared2(Value);
				return rtm::scalar_cast(rtm::scalar_sqrt(lengthSq));
			}
			else if constexpr (ComponentCount == 3)
			{
				return rtm::vector_length3(Value);
			}
			else
			{
				return rtm::vector_length(Value);
			}
		}

		void RTMCPP_VECTOR_CALL Normalize()
		{
			if constexpr (ComponentCount == 2)
			{
				Value = rtm::vector_normalize2(Value);
			}
			else if constexpr (ComponentCount == 3)
			{
				Value = rtm::vector_normalize3(Value);
			}
			else
			{
				Value = rtm::vector_normalize(Value);
			}
		}

		Vector RTMCPP_VECTOR_CALL Normalized() const
		{
			Vector result = *this;
			result.Normalize();
			return result;
		}

		ComponentType RTMCPP_VECTOR_CALL Cross(const Vector& other) const noexcept requires(ComponentCount == 3)
		{
			return rtm::vector_cross3(Value, other.Value);
		}

		ComponentType RTMCPP_VECTOR_CALL Dot(const Vector& other) const noexcept
		{
			if constexpr (ComponentCount == 2)
			{
				return rtm::vector_dot2(Value, other.Value);
			}
			else if constexpr (ComponentCount == 3)
			{
				return rtm::vector_dot3(Value, other.Value);
			}
			else
			{
				return rtm::vector_dot(Value, other.Value);
			}
		}

		ComponentType RTMCPP_VECTOR_CALL Distance(const Vector& other) const noexcept requires(ComponentCount == 3)
		{
			return rtm::vector_distance3(Value, other.Value);
		}
	};

	using Vec2 = Vector<float, 2>;
	using Vec3 = Vector<float, 3>;
	using Vec4 = Vector<float, 4>;

	using Vec2D = Vector<double, 2>;
	using Vec3D = Vector<double, 3>;
	using Vec4D = Vector<double, 4>;

}
