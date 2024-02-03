#pragma once

#include "Vector.hpp"

RTMCPP_EXPORT namespace rtmcpp {

	template<typename ComponentType>
	struct PackedVector2
	{
		ComponentType X;
		ComponentType Y;

		PackedVector2() noexcept = default;
		PackedVector2(const Vector<ComponentType, 2>& vec) noexcept
			: X(vec.X), Y(vec.Y) {}
		PackedVector2(ComponentType x, ComponentType y) noexcept
			: X(x), Y(y) {}

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
			: X(vec.X), Y(vec.Y), Z(vec.Z) {}
		PackedVector3(ComponentType x, ComponentType y, ComponentType z) noexcept
			: X(x), Y(y), Z(z) {}

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
			: X(vec.X), Y(vec.Y), Z(vec.Z), W(vec.W) {}
		PackedVector4(ComponentType x, ComponentType y, ComponentType z, ComponentType w) noexcept
			: X(x), Y(y), Z(z), W(w) {}

		operator Vector<ComponentType, 4>() const noexcept { return Vector<ComponentType, 4>{ X, Y, Z, W }; }
	};

	using PackedVec2 = PackedVector2<float>;
	using PackedVec3 = PackedVector3<float>;
	using PackedVec4 = PackedVector4<float>;

	using PackedVec2D = PackedVector2<double>;
	using PackedVec3D = PackedVector3<double>;
	using PackedVec4D = PackedVector4<double>;

}
