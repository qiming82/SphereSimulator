#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <unordered_map>
#include <vector>

#include "SPHExp.hpp"
#include "Buffer.hpp"

#define INVALID -1

class NeighborSphere {
  public:
    int gid;
    double radius;
    double radiusCollision;
    Evec3 pos;
    Evec3 posRelative;
    Equatn orientation;
};

class Sphere {
  public:
    int gid = INVALID;
    double radius;
    double radiusCollision;
    Evec3 pos;
    Evec3 vel;
    Evec3 omega;
    Equatn orientation;

    std::vector<NeighborSphere> sphNeighbor;
    std::unordered_map<std::string, SPHExp *> sphLayer;

    Sphere() = default;
    Sphere(const int & gid_, const double& radius_, const double& radiusCollision_) noexcept ;
    Sphere(const int & gid_, const double& radius_, const double& radiusCollision_, const Evec3 & pos_, const Equatn & orientation_ ) noexcept ;
    ~Sphere() noexcept;

    Sphere(const Sphere &) noexcept;
    Sphere(Sphere &&) noexcept;

    Sphere &operator=(Sphere) noexcept;

    void addLayer(const std::string &, SPHExp::KIND, int order = 4, const Equatn orientation = Equatn::Identity());

    void dumpSphere() const;
    void dumpLayer(const std::string &) const;

    void pack(Buffer & buffer);
    void unpack(const Buffer & buffer);

    friend void swap(Sphere &, Sphere &);
};

#endif // SPHERE_HPP