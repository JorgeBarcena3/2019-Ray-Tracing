#pragma once
#include "Render.h"

using namespace std;


Render::Render()
{
    myScene = nullptr;
}


Render::~Render()
{
}

bool Render::setProyectedShadow(const Ray& ray) {

    bool hit = false;
    hit_record sh;
    for (int i = 0; i < myScene->objectsToTrace.size() && !hit; i++)
        hit = myScene->objectsToTrace[i]->hit(ray, sh);

    return hit;

}


Ray Render::getShadowRay(const hit_record& record)
{

    return Ray(record.pointInWorld + record.normal * 0.01f, (myScene->light->lightCenter - record.pointInWorld).normalize());

}

vec3 Render::getColor(Ray& ray)
{

    if (ray.life > 0) {

        float currentDepthIndex = FLT_MAX;
        hit_record record;
        vec3* color = nullptr;

        for (int i = 0; i < myScene->objectsToTrace.size(); i++) {

            if (myScene->objectsToTrace[i]->hit(ray, record)) {

                if (record.pointAtRay < currentDepthIndex) {

                    currentDepthIndex = record.pointAtRay;

                    color = new vec3(0,0,0);

                    (*color) = myScene->ambientLight;

                    (*color) += vec3(myScene->objectsToTrace[i]->getColor(record, myScene));

                    vec3 L = (record.pointInWorld - myScene->light->lightCenter).normalize() * -1;
                    vec3 R = (record.pointInWorld - vec3(0,0,0)).normalize();

                    (*color) += applyReflection(record, ray) *
                                myScene->objectsToTrace[i]->myMaterial.specular *
                                powf(dot(L, R), 2);

                    if (setProyectedShadow(getShadowRay(record)))
                        *color = color->scalar(0.05f);
                 
                }

            }
        }

        return color == nullptr ? myScene->backgroundColor : color->colorClip();

    }

    return myScene->backgroundColor;

}

vec3 Render::applyReflection(const hit_record& record, Ray& ray)
{
    vec3 R = ray.direction - record.normal * ray.direction.dot(record.normal) * 2;
    R.normalize();
    Ray reflectionRay = Ray(record.pointInWorld + record.normal, R, ray.life - 25);
    return vec3( getColor(reflectionRay) );

}
