// Copyright(C) 2018 Tommy Hinks <tommy.hinks@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#include <vec_traits_passed_in_example.h>

#include <cassert>
#include <cstdint>
#include <fstream>

#include <thinks/poisson_disk_sampling/poisson_disk_sampling.h>

namespace {

struct Vec3 {
  float x;
  float y;
  float z;
};

struct Vec3Traits {
  typedef float ValueType;

  static constexpr auto kSize = 3;

  static ValueType Get(const Vec3& v, const std::size_t i) {
    return *(&v.x + i);
  }

  static void Set(Vec3* const v, const std::size_t i, const ValueType val) {
    *(&v->x + i) = val;
  }
};

}  // namespace

namespace examples {

void VecTraitsPassedInExample(const std::string& filename) {
  namespace pds = thinks::poisson_disk_sampling;

  constexpr auto radius = 2.f;
  const auto x_min = std::array<float, 3>{{-10.f, -10.f, -10.f}};
  const auto x_max = std::array<float, 3>{{10.f, 10.f, 10.f}};
  const auto samples = pds::PoissonDiskSampling<float, 3, Vec3, Vec3Traits>(
      radius, x_min, x_max);

  std::ofstream ofs{filename};
  assert(ofs);
  for (const auto& sample : samples) {
    ofs << sample.x << ", " << sample.y << ", " << sample.z << std::endl;
  }
  ofs.close();
}

}  // namespace examples
