/*
 *  Copyright (c) 2011, Los Alamos National Security, LLC.
 *  All rights Reserved.
 *
 *  Copyright 2011. Los Alamos National Security, LLC. This software was produced 
 *  under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National 
 *  Laboratory (LANL), which is operated by Los Alamos National Security, LLC 
 *  for the U.S. Department of Energy. The U.S. Government has rights to use, 
 *  reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR LOS 
 *  ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR 
 *  ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is modified
 *  to produce derivative works, such modified software should be clearly marked,
 *  so as not to confuse it with the version available from LANL.
 *
 *  Additionally, redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Los Alamos National Security, LLC, Los Alamos 
 *       National Laboratory, LANL, the U.S. Government, nor the names of its 
 *       contributors may be used to endorse or promote products derived from 
 *       this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE LOS ALAMOS NATIONAL SECURITY, LLC AND 
 *  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
 *  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL LOS ALAMOS NATIONAL
 *  SECURITY, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *  
 *  CLAMR -- LA-CC-11-094
 *  This research code is being developed as part of the 
 *  2011 X Division Summer Workshop for the express purpose
 *  of a collaborative code for development of ideas in
 *  the implementation of AMR codes for Exascale platforms
 *  
 *  AMR implementation of the Wave code previously developed
 *  as a demonstration code for regular grids on Exascale platforms
 *  as part of the Supercomputing Challenge and Los Alamos 
 *  National Laboratory
 *  
 *  Authors: Bob Robey       XCP-2   brobey@lanl.gov
 *           Neal Davis              davis68@lanl.gov, davis68@illinois.edu
 *           David Nicholaeff        dnic@lanl.gov, mtrxknight@aol.com
 *           Dennis Trujillo         dptrujillo@lanl.gov, dptru10@gmail.com
 * 
 */
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "graphics.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

static int magick_on = 0;

#ifdef HAVE_MAGICKWAND
#include <wand/MagickWand.h>

#define MAGICK_NCOLORS 1280

void Magick_Scale();

//static int graphics_movie = 0;
static MagickWand *magick_wand = NULL;
static DrawingWand *draw_wand  = NULL;
static PixelWand *pixel_wand   = NULL;

struct MagickColorTable {
   int Red;
   int Blue;
   int Green;
};

static struct MagickColorTable MagickRainbow[MAGICK_NCOLORS];
#endif


#define WINSIZE 800

void DrawSquaresToFile(int graph_num, int ncycle, double simTime, int rollback_img, int rollback_num);

/*
 * Variables that I added to make everything work for getting graphics
 * data output to files while running no graphics with CLAMR
 * Brian Atkinson
*/
static int autoscale = 0;
static double xconversion = 0.0;
static double yconversion = 0.0;
static int Ncolors = 256;
static int iteration = 0;

char *graphics_directory = "graphics_output";
int graphics_type; // type of graphics output

//static int mode = MOVE;

static int width;
static float graphics_xmin=0.0, graphics_xmax=0.0, graphics_ymin=0.0, graphics_ymax=0.0;

static int graphics_outline   = 0;
static int graphics_view_mode = 0;
static int graphics_mysize    = 0;

enum spatial_data_type {SPATIAL_DOUBLE, SPATIAL_FLOAT};
static int spatial_type = SPATIAL_FLOAT;

static double *x_double=NULL, *y_double=NULL, *dx_double=NULL, *dy_double=NULL;
static float *x_float=NULL, *y_float=NULL, *dx_float=NULL, *dy_float=NULL;

enum plot_data_type {DATA_DOUBLE, DATA_FLOAT};
static int data_type = DATA_FLOAT;
static double *data_double=NULL;
static float *data_float=NULL;
static int *graphics_proc=NULL;

void init_graphics_output(void){
   width = (WINSIZE / (graphics_ymax - graphics_ymin)) * (graphics_xmax - graphics_xmin);
   xconversion = (double)WINSIZE/ (graphics_xmax - graphics_xmin);
   yconversion = (double)WINSIZE/(graphics_ymax - graphics_ymin);

   struct stat stat_descriptor;
   if (stat(graphics_directory,&stat_descriptor) == -1){
     mkdir(graphics_directory,0777);
   }

   if (graphics_type != GRAPHICS_DATA && graphics_type != GRAPHICS_NONE) magick_on = 1;

#ifdef HAVE_MAGICKWAND
   if (magick_on){
      //MagickWandGenesis(); 
      // Create wand
      magick_wand = NewMagickWand();

      Magick_Scale();
   }
#endif
}

void terminate_graphics_output(void){
#ifdef HAVE_MAGICKWAND
   if (magick_on){
      magick_wand = DestroyMagickWand(magick_wand);
      MagickWandTerminus();
   }
#endif
}

void set_graphics_window(float graphics_xmin_in, float graphics_xmax_in, float graphics_ymin_in, float graphics_ymax_in){
   graphics_xmin = graphics_xmin_in;
   graphics_xmax = graphics_xmax_in;
   graphics_ymin = graphics_ymin_in;
   graphics_ymax = graphics_ymax_in;
}
void set_graphics_cell_data_double(double *data_in){
   data_type = DATA_DOUBLE;
   data_double = data_in;
}
void set_graphics_cell_data_float(float *data_in){
   data_type = DATA_FLOAT;
   data_float = data_in;
}
void set_graphics_cell_proc(int *graphics_proc_in){
   graphics_proc = graphics_proc_in;
}
void set_graphics_cell_coordinates_double(double *x_in, double *dx_in, double *y_in, double *dy_in){
   spatial_type = SPATIAL_DOUBLE;
   x_double = x_in;
   dx_double = dx_in;
   y_double = y_in;
   dy_double = dy_in;
}
void set_graphics_cell_coordinates_float(float *x_in, float *dx_in, float *y_in, float *dy_in){
   spatial_type = SPATIAL_FLOAT;
   x_float = x_in;
   dx_float = dx_in;
   y_float = y_in;
   dy_float = dy_in;
}
void set_graphics_viewmode(int graphics_view_mode_in){
   graphics_view_mode = graphics_view_mode_in;
}
void set_graphics_mysize(int graphics_mysize_in){
   graphics_mysize = graphics_mysize_in;
}
void set_graphics_outline(int graphics_outline_in){
   graphics_outline = graphics_outline_in;
}

/*
 * Created this function get graphics data while running
 * the no graphic version of CLAMR. The output for the main
 * cell data is written out to graph#.data files and the gridline
 * data is writeen out to outline#.lin files.
 * Brian Atkinson
*/
void DrawSquaresToFile(int graph_num, int ncycle, double simTime, int rollback_img, int rollback_num){
#ifdef HAVE_MAGICKWAND
   if (magick_on) {
      draw_wand   = NewDrawingWand();
      pixel_wand  = NewPixelWand();

      MagickSetSize(magick_wand,WINSIZE,WINSIZE);
      MagickSetColorspace(magick_wand,sRGBColorspace);
      MagickReadImage(magick_wand,"xc:white");

      DrawSetViewbox(draw_wand, 0, 0, WINSIZE, WINSIZE);
      DrawScale(draw_wand, xconversion, -yconversion);
      DrawTranslate(draw_wand, -graphics_xmin, graphics_ymin);

      int npart = graphics_mysize/16;
      for (int i=0; i<graphics_mysize; i++){
         graphics_proc[i] = i/npart;
      }

      int magick_step = MAGICK_NCOLORS/(graphics_proc[graphics_mysize-1]+1);

      if (graphics_outline) {
         PixelGetBlack(pixel_wand);

         DrawSetStrokeColor(draw_wand,pixel_wand);
         DrawSetStrokeWidth(draw_wand,0.01);
         DrawSetStrokeAntialias(draw_wand,1);
         DrawSetStrokeOpacity(draw_wand,1);
      }

      if (data_type == DATA_DOUBLE){

         for(int i = 0; i < graphics_mysize; i++) {
            int magick_color = graphics_proc[i]*magick_step;
            char cstring[40];
            sprintf(cstring,"rgba(%d,%d,%d,%d)",MagickRainbow[magick_color].Red,
                                                MagickRainbow[magick_color].Green,
                                                MagickRainbow[magick_color].Blue,120);
            PixelSetColor(pixel_wand, cstring);
            

            DrawSetFillColor(draw_wand, pixel_wand); 

            DrawRectangle(draw_wand, x_double[i],              y_double[i],
                                     x_double[i]+dx_double[i], y_double[i]+dy_double[i]);
/*
           printf("DEBUG -- i %d magick_color %d magick_step %d graphics_proc %d cstring %s corners %lg %lg %lg %lg\n",
               i,magick_color,magick_step,graphics_proc[i],cstring,
               x_double[i],              y_double[i],
               x_double[i]+dx_double[i], y_double[i]+dy_double[i]);
*/
         }

         if (graphics_outline) {
	    PixelSetColor(pixel_wand,"black");
	    DrawSetStrokeColor(draw_wand,pixel_wand);
	    DrawSetStrokeWidth(draw_wand,0.01);

            double xold = x_double[0]+0.5*dx_double[0];
            double yold = y_double[0]+0.5*dy_double[0];

            for(int i = 0; i < graphics_mysize; i++) {
               char cstring[40];
               sprintf(cstring,"%d",i);

               double xnew = x_double[i]+0.5*dx_double[i];
               double ynew = y_double[i]+0.5*dy_double[i];

               DrawLine(draw_wand, xold, yold, xnew, ynew);

               xold = xnew;
               yold = ynew;
            }
         }

/*
         // Set up a 12 point black font 
	 PixelSetColor(pixel_wand,"black");
	 DrawSetFillColor(draw_wand,pixel_wand);
	 DrawSetFont (draw_wand, "Courier" ) ;
	 DrawSetFontSize(draw_wand,0.01);
	 DrawSetStrokeColor(draw_wand,pixel_wand);
	 DrawSetStrokeWidth(draw_wand,0.01);
         DrawSetTextDirection(draw_wand, RightToLeftDirection);
         DrawSetTextAlignment(draw_wand, CenterAlign);
         DrawSetTextAntialias(draw_wand,MagickTrue);

         for(int i = 1; i < graphics_mysize; i++) {
            char cstring[40];
            sprintf(cstring,"%d",i);


            DrawAnnotation(draw_wand, x_double[i]+0.5*dx_double[i], y_double[i]+0.5*dy_double[i], cstring);
         }
*/

      } else {

         for(int i = 0; i < graphics_mysize; i++) {
            int magick_color = graphics_proc[i]*magick_step;
            char cstring[40];
            sprintf(cstring,"rgba(%d,%d,%d,%d)",MagickRainbow[magick_color].Red,
                                                MagickRainbow[magick_color].Green,
                                                MagickRainbow[magick_color].Blue,120);
            PixelSetColor(pixel_wand, cstring);

            DrawSetFillColor(draw_wand, pixel_wand);

            DrawRectangle(draw_wand, x_float[i],             y_float[i],
                                     x_float[i]+dx_float[i], y_float[i]+dy_float[i]);
         }

         if (graphics_outline) {
	    PixelSetColor(pixel_wand,"black");
	    DrawSetStrokeColor(draw_wand,pixel_wand);
	    DrawSetStrokeWidth(draw_wand,0.01);

            float xold = x_float[0]+0.5*dx_float[0];
            float yold = y_float[0]+0.5*dy_float[0];

            for(int i = 0; i < graphics_mysize; i++) {
               char cstring[40];
               sprintf(cstring,"%d",i);

               float xnew = x_float[i]+0.5*dx_float[i];
               float ynew = y_float[i]+0.5*dy_float[i];

               DrawLine(draw_wand, xold, yold, xnew, ynew);

               xold = xnew;
               yold = ynew;
            }
         }

      }

      MagickDrawImage(magick_wand, draw_wand);

      char filename[50];
      char graphics_file_extension[10];
      if (graphics_type == GRAPHICS_BMP)  strcpy(graphics_file_extension,".bmp");
      if (graphics_type == GRAPHICS_GIF)  strcpy(graphics_file_extension,".gif");
      if (graphics_type == GRAPHICS_JPEG) strcpy(graphics_file_extension,".jpeg");
      if (graphics_type == GRAPHICS_MPEG) strcpy(graphics_file_extension,".mpeg");
      if (graphics_type == GRAPHICS_PDF)  strcpy(graphics_file_extension,".pdf");
      if (graphics_type == GRAPHICS_PNG)  strcpy(graphics_file_extension,".png");
      if (graphics_type == GRAPHICS_SVG)  strcpy(graphics_file_extension,".svg");
      sprintf(filename,"%s/graph%05d%s", graphics_directory, graph_num, graphics_file_extension);
      MagickWriteImage(magick_wand, filename);
      //MagickDisplayImage(magick_wand, "x:");

      draw_wand = DestroyDrawingWand(draw_wand);
      pixel_wand = DestroyPixelWand(pixel_wand);
   }
#endif

   if (graphics_type == GRAPHICS_DATA){
      int i, color;
      int step = Ncolors/(graphics_proc[graphics_mysize-1]+1);
      int xloc, xwid, yloc, ywid;
      int xloc1, xloc2, yloc1, yloc2;
      char filename[50], filename2[50];
   
      if(rollback_img){
         sprintf(filename,"%s/graph%dcp%05d.data", graphics_directory, graph_num, rollback_num);
         sprintf(filename2,"%s/outline%dcp%05d.lin",graphics_directory, graph_num, rollback_num);
      }
      else{
         sprintf(filename,"%s/graph%05d.data", graphics_directory, graph_num);
         sprintf(filename2,"%s/outline%05d.lin",graphics_directory, graph_num);
      }
      FILE *fp = fopen(filename,"w");
      FILE *fp2 = fopen(filename2,"w");
      if(fp && fp2){
         fprintf(fp,"%d,%lf\n",ncycle,simTime);
         if (data_type == DATA_DOUBLE){
            for(i = 0; i < graphics_mysize; i++) {
               xloc = (int)((x_double[i]-graphics_xmin)*xconversion);
               xwid = (int)((x_double[i]+dx_double[i]-graphics_xmin)*xconversion-xloc);
               yloc = (int)((graphics_ymax-(y_double[i]+dy_double[i]))*yconversion);
               ywid = (int)((graphics_ymax-y_double[i])*yconversion);
               ywid -= yloc;
               color = graphics_proc[i]*step;
               //fprintf(fp,"%d,%d,%d,%d,%f\n",xloc,yloc,xwid,ywid,data[i]);
               fprintf(fp,"%d,%d,%d,%d,%d\n",xloc,yloc,xwid,ywid,color);
            
               xloc1 = (int)((x_double[i]-graphics_xmin)*xconversion);
               xloc2 = (int)((x_double[i]+dx_double[i]-graphics_xmin)*xconversion);
               yloc1 = (int)((graphics_ymax-y_double[i])*yconversion);
               yloc2 = (int)((graphics_ymax-(y_double[i]+dy_double[i]))*yconversion);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc2,xloc2,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc2,yloc1);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc1,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc2,yloc1,xloc2,yloc2);
            }
         } else {
            for(i = 0; i < graphics_mysize; i++) {
               xloc = (int)((x_float[i]-graphics_xmin)*xconversion);
               xwid = (int)((x_float[i]+dx_float[i]-graphics_xmin)*xconversion-xloc);
               yloc = (int)((graphics_ymax-(y_float[i]+dy_float[i]))*yconversion);
               ywid = (int)((graphics_ymax-y_float[i])*yconversion);
               ywid -= yloc;
               color = graphics_proc[i]*step;
               //fprintf(fp,"%d,%d,%d,%d,%f\n",xloc,yloc,xwid,ywid,data[i]);
               fprintf(fp,"%d,%d,%d,%d,%d\n",xloc,yloc,xwid,ywid,color);
         
               xloc1 = (int)((x_float[i]-graphics_xmin)*xconversion);
               xloc2 = (int)((x_float[i]+dx_float[i]-graphics_xmin)*xconversion);
               yloc1 = (int)((graphics_ymax-y_float[i])*yconversion);
               yloc2 = (int)((graphics_ymax-(y_float[i]+dy_float[i]))*yconversion);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc2,xloc2,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc2,yloc1);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc1,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc2,yloc1,xloc2,yloc2);
            }
         }
         fclose(fp);
         fclose(fp2);
         iteration++;
      }   
      else{
            if(fp == NULL){
               printf("Could not create %s in DrawSqaures\n", filename);
            }
            else{
               printf("Could not create %s in DrawSqaures\n", filename2);
            }
      }
   }
}

/*
 * Created this function get graphics data while running
 * the no graphic version of CLAMR. The output for the main
 * cell data is written out to graph#.data files and the gridline
 * data is writeen out to outline#.lin files.
 * Brian Atkinson
*/
void DisplayStateToFile(int graph_num, int ncycle, double simTime, int rollback_img, int rollback_num){
#ifdef HAVE_MAGICKWAND
   if (magick_on) {
      double scaleMax = 25.0, scaleMin = 0.0;

      draw_wand   = NewDrawingWand();
      pixel_wand  = NewPixelWand();

      MagickSetSize(magick_wand,WINSIZE,WINSIZE);
      MagickSetColorspace(magick_wand,sRGBColorspace);
      MagickReadImage(magick_wand,"xc:white");

      DrawSetViewbox(draw_wand, 0, 0, WINSIZE, WINSIZE);
      DrawScale(draw_wand, xconversion, -yconversion);
      DrawTranslate(draw_wand, -graphics_xmin, graphics_ymin);

      if (autoscale) {
         scaleMax=-1.0e30;
         scaleMin=1.0e30;
         if (data_type == DATA_DOUBLE){
            for(int i = 0; i<graphics_mysize; i++) {
               if (data_double[i] > scaleMax) scaleMax = data_double[i];
               if (data_double[i] < scaleMin) scaleMin = data_double[i];
            }
         } else {
            for(int i = 0; i<graphics_mysize; i++) {
               if (data_float[i] > scaleMax) scaleMax = data_float[i];
               if (data_float[i] < scaleMin) scaleMin = data_float[i];
            }
         }
      }

      int magick_step = MAGICK_NCOLORS/(scaleMax - scaleMin);

      if (graphics_outline) {
         PixelGetBlack(pixel_wand);

         DrawSetStrokeColor(draw_wand,pixel_wand);
         DrawSetStrokeWidth(draw_wand,0.01);
         DrawSetStrokeAntialias(draw_wand,1);
         DrawSetStrokeOpacity(draw_wand,1);
      }

      if (data_type == DATA_DOUBLE){

         for(int i = 0; i < graphics_mysize; i++) {
            int magick_color;
            if (data_type == DATA_DOUBLE){
               magick_color = (int)(data_double[i]-scaleMin)*magick_step;
            } else {
               magick_color = (int)(data_float[i]-scaleMin)*magick_step;
            }
            magick_color = MAGICK_NCOLORS-magick_color;
            if (magick_color < 0) {
               magick_color=0;
            }
            if (magick_color >= MAGICK_NCOLORS) magick_color = MAGICK_NCOLORS-1;

            char cstring[40];
            sprintf(cstring,"rgba(%d,%d,%d,%d)",MagickRainbow[magick_color].Red,
                                                MagickRainbow[magick_color].Green,
                                                MagickRainbow[magick_color].Blue,120);
            PixelSetColor(pixel_wand, cstring);

            DrawSetFillColor(draw_wand, pixel_wand);

            DrawRectangle(draw_wand, x_double[i],              y_double[i],
                                     x_double[i]+dx_double[i], y_double[i]+dy_double[i]);
/*
           printf("DEBUG -- i %d magick_color %d magick_step %d graphics_proc %d cstring %s corners %lg %lg %lg %lg\n",
               i,magick_color,magick_step,graphics_proc[i],cstring,
               x_double[i],              y_double[i],
               x_double[i]+dx_double[i], y_double[i]+dy_double[i]);
*/
         }
      } else {

         for(int i = 0; i < graphics_mysize; i++) {
            int magick_color;
            if (data_type == DATA_DOUBLE){
               magick_color = (int)(data_double[i]-scaleMin)*magick_step;
            } else {
               magick_color = (int)(data_float[i]-scaleMin)*magick_step;
            }
            magick_color = MAGICK_NCOLORS-magick_color;
            if (magick_color < 0) {
               magick_color=0;
            }
            if (magick_color >= MAGICK_NCOLORS) magick_color = MAGICK_NCOLORS-1;

            char cstring[40];
            sprintf(cstring,"rgba(%d,%d,%d,%d)",MagickRainbow[magick_color].Red,
                                                MagickRainbow[magick_color].Green,
                                                MagickRainbow[magick_color].Blue,120);
            PixelSetColor(pixel_wand, cstring);

            DrawSetFillColor(draw_wand, pixel_wand);

            DrawRectangle(draw_wand, x_float[i],             y_float[i],
                                     x_float[i]+dx_float[i], y_float[i]+dy_float[i]);
         }
      }

      MagickDrawImage(magick_wand, draw_wand);

      char filename[50];
      char graphics_file_extension[10];
      if (graphics_type == GRAPHICS_BMP)  strcpy(graphics_file_extension,".bmp");
      if (graphics_type == GRAPHICS_GIF)  strcpy(graphics_file_extension,".gif");
      if (graphics_type == GRAPHICS_JPEG) strcpy(graphics_file_extension,".jpeg");
      if (graphics_type == GRAPHICS_MPEG) strcpy(graphics_file_extension,".mpeg");
      if (graphics_type == GRAPHICS_PDF)  strcpy(graphics_file_extension,".pdf");
      if (graphics_type == GRAPHICS_PNG)  strcpy(graphics_file_extension,".png");
      if (graphics_type == GRAPHICS_SVG)  strcpy(graphics_file_extension,".svg");
      sprintf(filename,"%s/graph%05d%s", graphics_directory, graph_num, graphics_file_extension);
      MagickWriteImage(magick_wand, filename);
      //MagickDisplayImage(magick_wand, "x:");

      draw_wand = DestroyDrawingWand(draw_wand);
      pixel_wand = DestroyPixelWand(pixel_wand);
   }
#endif
   if (graphics_type == GRAPHICS_DATA){
      double scaleMax = 25.0, scaleMin = 0.0;
      int i;
      int color;
      char filename[50], filename2[50];
   
      if(rollback_img){
         sprintf(filename,"%s/graph%dcp%05d.data", graphics_directory, graph_num, rollback_num);
         sprintf(filename2,"%s/outline%dcp%05d.lin",graphics_directory, graph_num, rollback_num);
      }
      else{
         sprintf(filename,"%s/graph%05d.data", graphics_directory, graph_num);
         sprintf(filename2,"%s/outline%05d.lin",graphics_directory, graph_num);
      }
      FILE *fp = fopen(filename,"w");
      FILE *fp2 = fopen(filename2,"w");
      if(fp && fp2){
         fprintf(fp,"%d,%lf\n",ncycle,simTime);
         if (autoscale) {
            scaleMax=-1.0e30;
            scaleMin=1.0e30;
            if (data_type == DATA_DOUBLE){
               for(i = 0; i<graphics_mysize; i++) {
                  if (data_double[i] > scaleMax) scaleMax = data_double[i];
                  if (data_double[i] < scaleMin) scaleMin = data_double[i];
               }
            } else {
               for(i = 0; i<graphics_mysize; i++) {
                  if (data_float[i] > scaleMax) scaleMax = data_float[i];
                  if (data_float[i] < scaleMin) scaleMin = data_float[i];
               }
            }
         }

         double step = Ncolors/(scaleMax - scaleMin);
         int xloc, xwid, yloc, ywid;
         int xloc1, xloc2, yloc1, yloc2;
         for(i = 0; i < graphics_mysize; i++) {
            if (data_type == DATA_DOUBLE){
               color = (int)(data_double[i]-scaleMin)*step;
            } else {
               color = (int)(data_float[i]-scaleMin)*step;
            }
            color = Ncolors-color;
            if (color < 0) {
               color=0;
            }
            if (color >= Ncolors) color = Ncolors-1;

            if (data_type == DATA_DOUBLE){
               xloc = (int)((x_double[i]-graphics_xmin)*xconversion);
               xwid = (int)((x_double[i]+dx_double[i]-graphics_xmin)*xconversion-xloc);
               yloc = (int)((graphics_ymax-(y_double[i]+dy_double[i]))*yconversion);
               ywid = (int)((graphics_ymax-y_double[i])*yconversion);
               ywid -= yloc;
               //fprintf(fp,"%d,%d,%d,%d,%f\n",xloc,yloc,xwid,ywid,data[i]);
               fprintf(fp,"%d,%d,%d,%d,%d\n",xloc,yloc,xwid,ywid,color);
         
               xloc1 = (int)((x_double[i]-graphics_xmin)*xconversion);
               xloc2 = (int)((x_double[i]+dx_double[i]-graphics_xmin)*xconversion);
               yloc1 = (int)((graphics_ymax-y_double[i])*yconversion);
               yloc2 = (int)((graphics_ymax-(y_double[i]+dy_double[i]))*yconversion);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc2,xloc2,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc2,yloc1);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc1,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc2,yloc1,xloc2,yloc2);
            } else {
               xloc = (int)((x_float[i]-graphics_xmin)*xconversion);
               xwid = (int)((x_float[i]+dx_float[i]-graphics_xmin)*xconversion-xloc);
               yloc = (int)((graphics_ymax-(y_float[i]+dy_float[i]))*yconversion);
               ywid = (int)((graphics_ymax-y_float[i])*yconversion);
               ywid -= yloc;
               //fprintf(fp,"%d,%d,%d,%d,%f\n",xloc,yloc,xwid,ywid,data[i]);
               fprintf(fp,"%d,%d,%d,%d,%d\n",xloc,yloc,xwid,ywid,color);
         
               xloc1 = (int)((x_float[i]-graphics_xmin)*xconversion);
               xloc2 = (int)((x_float[i]+dx_float[i]-graphics_xmin)*xconversion);
               yloc1 = (int)((graphics_ymax-y_float[i])*yconversion);
               yloc2 = (int)((graphics_ymax-(y_float[i]+dy_float[i]))*yconversion);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc2,xloc2,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc2,yloc1);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc1,yloc1,xloc1,yloc2);
               fprintf(fp2,"%d,%d,%d,%d\n",xloc2,yloc1,xloc2,yloc2);
            }
         }
         fclose(fp);
         fclose(fp2);   
         iteration++;
     }
     else{
        if(fp == NULL){
            printf("Could not open %s in DisplayStateToFile\n", filename);
        }
        else{
            printf("Could not open %s in DisplayStateToFile\n", filename2);
        }
     }
  }
}

void write_graphics_info(int graph_num, int ncycle, double simTime, int rollback_img, int rollback_num){
   if (graphics_view_mode == 0) {
      DrawSquaresToFile(graph_num, ncycle, simTime, rollback_img, rollback_num);
   } else {
      DisplayStateToFile(graph_num, ncycle, simTime, rollback_img, rollback_num);
   }
}

#ifdef HAVE_MAGICKWAND
void Magick_Scale() {
   int i, r;
   for (i=0, r=0;   i<256; i++, r++) {
         MagickRainbow[     i].Red   = 0;
         MagickRainbow[     i].Green = r;
         MagickRainbow[     i].Blue  = 255;
   }
   for (i=0, r=255; i<256; i++, r--) {
         MagickRainbow[ 256+i].Red   = 0;
         MagickRainbow[ 256+i].Green = 255;
         MagickRainbow[ 256+i].Blue  = r;
   }
   for (i=0, r=0;   i<256; i++, r++) {
         MagickRainbow[ 512+i].Red   = r;
         MagickRainbow[ 512+i].Green = 255;
         MagickRainbow[ 512+i].Blue  = 0;
   }
   for (i=0, r=255; i<256; i++, r--) {
         MagickRainbow[ 768+i].Red   = 255;
         MagickRainbow[ 768+i].Green = r;
         MagickRainbow[ 768+i].Blue  = 0;
   }
   for (i=0, r=0;   i<256; i++, r++) {
         MagickRainbow[1024+i].Red   = 255;
         MagickRainbow[1024+i].Green = 0;
         MagickRainbow[1024+i].Blue  = r;
   }
}
#endif

