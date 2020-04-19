#ifndef TRAJP_H
#define TRAJP_H
#include <ros/ros.h>
#include <Eigen/Geometry>
#include <geometry_msgs/Pose.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
#include "occgrid.hpp"
using namespace std;

class TrajectoryPlanner
{
    public:
        TrajectoryPlanner();
        virtual ~TrajectoryPlanner();
        void getTrajectories();
        void getCmaes();
        pair<float,float> carPoint2World(float x, float y, const geometry_msgs::Pose &current_pose);
        void trajectory2world(const geometry_msgs::Pose &current_pose);
        visualization_msgs::MarkerArray gen_markers(const vector<pair<float,float>> &points, float r=0, float g=1, float b=0);
        vector<pair<float,float>> trajectories_world;
        int best_traj(OccGrid &occ_grid);
        vector<pair<float,float>> cmaes_traj;
        

    private:
        bool successfulRead;
        void publish_marker(float x, float y);
        vector<pair<float,float>> trajectories;
        
        // mode
};

#endif