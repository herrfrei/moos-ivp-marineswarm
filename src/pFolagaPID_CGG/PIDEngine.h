/*****************************************************************/
/*    NAME: Michael Benjamin, Henrik Schmidt, and John Leonard   */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: PIDEngine.h                                          */
/*    DATE: Jul 31st, 2005 Sunday in Montreal                    */
/*                                                               */
/* This program is free software; you can redistribute it and/or */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation; either version  */
/* 2 of the License, or (at your option) any later version.      */
/*                                                               */
/* This program is distributed in the hope that it will be       */
/* useful, but WITHOUT ANY WARRANTY; without even the implied    */
/* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR       */
/* PURPOSE. See the GNU General Public License for more details. */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with this program; if not, write to the Free    */
/* Software Foundation, Inc., 59 Temple Place - Suite 330,       */
/* Boston, MA 02111-1307, USA.                                   */
/*****************************************************************/
/*                                                               */
/* Modified by :  Nathan Vandervaeren                            */
/* Date :         April 2014                                     */
/* Application :  pFolagaPID_CGG                                 */
/*                                                               */
/*****************************************************************/

#ifndef MARINE_PIDENGINE_HEADER
#define MARINE_PIDENGINE_HEADER

#include <vector>
#include <string>
#include "ScalarPID.h"
#include "SimMap/DragMap.h"

class PIDEngine {
public:
  PIDEngine();
  ~PIDEngine() {};

  void setPID(int, ScalarPID);
  void updateTime(double ctime)     {m_current_time = ctime;};

  double getDesiredSurgeThrust(double desired_speed, 
                               double current_speed,
                               double current_surge_thrust,
                               double max_surge_thrust,
                               double max_speed,
                               double current_heading,
                               double desired_heading,
                               double heading_limit,
                               DragMap dmap,
                               bool spdPID_active);
                               
  double getDesiredHeadingThrust(double desired_heading, 
                                 double current_heading,
                                 double max_heading_thrust);
                                 
  double getDesiredPitchThrust(double desired_depth, 
                               double current_depth,
                               double current_pitch,
                               double max_pitch,
                               double max_pitch_thrust);

  void clearReport() {m_pid_report.clear();};
  std::vector<std::string> getPIDReport() {return(m_pid_report);};

protected:
  ScalarPID m_heading_pid;
  ScalarPID m_speed_pid;
  ScalarPID m_z_to_pitch_pid;
  ScalarPID m_pitch_pid;

  double  m_current_time;

  std::vector<std::string> m_pid_report;
};
#endif












