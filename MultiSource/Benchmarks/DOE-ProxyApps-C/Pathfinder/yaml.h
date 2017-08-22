/*************************************************************************
 *
 *        PathFinder: finding a series of labeled nodes within a
 *                two-layer directed, cyclic graph.
 *               Copyright (2013) Sandia Corporation
 *
 * Copyright (2013) Sandia Corporation. Under the terms of Contract 
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government 
 * retains certain rights in this software.
 *
 * This file is part of PathFinder.
 * 
 * PathFinder is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * PathFinder is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PathFinder.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Questions? Contact J. Brian Rigdon (jbrigdo@sandia.gov)
 *
 */
 
/*
 * yaml.h
 *
 *  Created on: Jun 21, 2013
 *      Author: J. Brian Rigdon
 */
 
 #ifndef YAML_H
 #define YAML_H
 
 void YAMLOpen();
 void YAMLClose();
 void YAMLWriteString(char *tag, char *data);
 void YAMLWriteInt(char *tag, int data);
 void YAMLWriteDouble(char *tag, double data);
 void YAMLWriteFloat(char *tag, float data);
 
 #endif /* YAML_H */