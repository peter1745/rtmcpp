#pragma once

#include "Vector.hpp"

namespace rtmcpp {

	template<typename ComponentType>
	struct PackedVector2
	{
		ComponentType X;
		ComponentType Y;

		PackedVector2() noexcept = default;
		PackedVector2(const Vector<ComponentType, 2>& vec) noexcept
			: X(vec.X), Y(vec.Y)
		{
		}

		operator Vector<ComponentType, 2>() const noexcept { return Vector<ComponentType, 2>{ X, Y }; }
	};

	template<typename ComponentType>
	struct PackedVector3
	{
		ComponentType X;
		ComponentType Y;
		ComponentType Z;

		PackedVector3() noexcept = default;
		PackedVector3(const Vector<ComponentType, 3>& vec) noexcept
			: X(vec.X), Y(vec.Y), Z(vec.Z)
		{
		}

		operator Vector<ComponentType, 3>() const noexcept { return Vector<ComponentType, 3>{ X, Y, Z }; }
	};

	template<typename ComponentType>
	struct PackedVector4
	{
		ComponentType X;
		ComponentType Y;
		ComponentType Z;
		ComponentType W;

		PackedVector4() noexcept = default;
		PackedVector4(const Vector<ComponentType, 4>& vec) noexcept
			: X(vec.X), Y(vec.Y), Z(vec.Z), W(vec.W)
		{
		}

		operator Vector<ComponentType, 4>() const noexcept { return Vector<ComponentType, 4>{ X, Y, Z, W }; }
	};

	using PackedVec2f = PackedVector2<float>;
	using PackedVec3f = PackedVector3<float>;
	using PackedVec4f = PackedVector4<float>;

	using PackedVec2d = PackedVector2<double>;
	using PackedVec3d = PackedVector3<double>;
	using PackedVec4d = PackedVector4<double>;

}
