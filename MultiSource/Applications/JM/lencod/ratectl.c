
/*!
 ***************************************************************************
 * \file ratectl.c
 *
 * \brief
 *    Rate Control algorithm
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *     - Siwei Ma <swma@jdl.ac.cn>
 *     - Zhengguo LI<ezgli@lit.a-star.edu.sg>
 *
 * \date
 *   16 Jan. 2003
 **************************************************************************
 */

#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "global.h"
#include "ratectl.h"

const double THETA=1.3636;
const int Switch=0;

int Iprev_bits=0;
int Pprev_bits=0;


/* rate control variables */
int Xp, Xb;
static int R,T_field;
static int Np, Nb, bits_topfield;
long T,T1;
//HRD consideration
long UpperBound1, UpperBound2, LowerBound;
double InitialDelayOffset;
const double OMEGA=0.9;

double Wp,Wb; 
int TotalPFrame;
int DuantQp; 
int PDuantQp;
FILE *BitRate;
double DeltaP;


/*! 
 *************************************************************************************
 * \brief
 *    Dynamically allocate memory needed for rate control
 *
 *************************************************************************************
*/
void rc_alloc()
{
  img->MADofMB = (double*) calloc (img->FrameSizeInMbs, sizeof (double));
  if (NULL==img->MADofMB)
  {
    no_mem_exit("rc_alloc: img->MADofMB");
  }
  
  BUPFMAD = (double*) calloc ((img->FrameSizeInMbs/input->basicunit), sizeof (double));
  if (NULL==BUPFMAD)
  {
    no_mem_exit("rc_alloc: img->BUPFMAD");
  }

  BUCFMAD = (double*) calloc ((img->FrameSizeInMbs/input->basicunit), sizeof (double));
  if (NULL==BUCFMAD)
  {
    no_mem_exit("rc_alloc: img->BUCFMAD");
  }

  FCBUCFMAD = (double*) calloc ((img->FrameSizeInMbs/input->basicunit), sizeof (double));
  if (NULL==FCBUCFMAD)
  {
    no_mem_exit("rc_alloc: img->FCBUCFMAD");
  }

  FCBUPFMAD = (double*) calloc ((img->FrameSizeInMbs/input->basicunit), sizeof (double));
  if (NULL==FCBUPFMAD)
  {
    no_mem_exit("rc_alloc: img->FCBUPFMAD");
  }

}

/*! 
 *************************************************************************************
 * \brief
 *    Free memory needed for rate control
 *
 *************************************************************************************
*/
void rc_free()
{
  if (NULL!=img->MADofMB)
  {
    free (img->MADofMB);
    img->MADofMB = NULL;
  }
  if (NULL!=BUPFMAD)
  {
    free (BUPFMAD);
    BUPFMAD = NULL;
  }
  if (NULL!=BUCFMAD)
  {
    free (BUCFMAD);
    BUCFMAD = NULL;
  }
  if (NULL!=FCBUCFMAD)
  {
    free (FCBUCFMAD);
    FCBUCFMAD = NULL;
  }
  if (NULL!=FCBUPFMAD)
  {
    free (FCBUPFMAD);
    FCBUPFMAD = NULL;
  }
}


/*! 
 *************************************************************************************
 * \brief
 *    Initialize rate control parameters
 *
 *************************************************************************************
*/
void rc_init_seq()
{
  double L1,L2,L3,bpp;
  int qp;
  int i;
  
  Xp=0;
  Xb=0;
   
  bit_rate=input->bit_rate;
  frame_rate = (img->framerate *(float)(input->successive_Bframe + 1)) / (float) (input->jumpd + 1);
  PreviousBit_Rate=bit_rate;
   
  /*compute the total number of MBs in a frame*/
  
  img->Frame_Total_Number_MB=img->height*img->width/256;
  if(input->basicunit>img->Frame_Total_Number_MB)
    input->basicunit=img->Frame_Total_Number_MB;
  if(input->basicunit<img->Frame_Total_Number_MB)
    TotalNumberofBasicUnit=img->Frame_Total_Number_MB/input->basicunit;
  
  MINVALUE=4.0;
  /*initialize the parameters of fluid flow traffic model*/
  
  BufferSize=bit_rate*2.56;
  CurrentBufferFullness=0;
  GOPTargetBufferLevel=CurrentBufferFullness;
  /*HRD consideration*/
  InitialDelayOffset=BufferSize*0.8;
  
  /*initialize the previous window size*/
  m_windowSize=0;
  MADm_windowSize=0;
  img->NumberofCodedBFrame=0;
  img->NumberofCodedPFrame=0;
  img->NumberofGOP=0;
  /*remaining # of bits in GOP */
  R = 0;
  /*control parameter */
  if(input->successive_Bframe>0)
  {
    GAMMAP=0.25;
    BETAP=0.9;
  }
  else
  {
    GAMMAP=0.5;
    BETAP=0.5;
  }
  
  /*quadratic rate-distortion model*/
  PPreHeader=0;
  
  Pm_X1=bit_rate*1.0;
  Pm_X2=0.0;
  /* linear prediction model for P picture*/
  PMADPictureC1=1.0;
  PMADPictureC2=0.0;
  
  for(i=0;i<20;i++)
  {
    Pm_rgQp[i]=0;
    Pm_rgRp[i]=0.0;
    PPictureMAD[i]=0.0;
  }
  PPictureMAD[20]=0.0;
   
  //Define the largest variation of quantization parameters
  PDuantQp=2;
  
  /*basic unit layer rate control*/
  PAveHeaderBits1=0;
  PAveHeaderBits3=0;  
  if(TotalNumberofBasicUnit>=9)
    DDquant=1;
  else
    DDquant=2;
  
  MBPerRow=img->width/16;
  
  /*adaptive field/frame coding*/
  img->FieldControl=0;
  
  RC_MAX_QUANT = 51;  // clipping
  RC_MIN_QUANT = 0;//clipping
  
  /*compute the initial QP*/
  bpp = 1.0*bit_rate /(frame_rate*img->width*img->height);
  if (img->width == 176) 
  {
    L1 = 0.1;
    L2 = 0.3;
    L3 = 0.6;
  }else if (img->width == 352)
  {
    L1 = 0.2;
    L2 = 0.6;
    L3 = 1.2;
  }else 
  {
    L1 = 0.6;
    L2 = 1.4;
    L3 = 2.4;
  }
  
  if (input->SeinitialQP==0)
  {
    if(bpp<= L1)
      qp = 35;
    else
      if(bpp<=L2)
        qp = 25;
      else
        if(bpp<=L3)
          qp  = 20;
        else
          qp =10;
    input->SeinitialQP = qp;
  }
}

/*! 
 *************************************************************************************
 * \brief
 *    Initialize one GOP
 *
 *************************************************************************************
*/
void rc_init_GOP(int np, int nb)
{
  Boolean Overum=FALSE;
  int OverBits;
  int OverDuantQp;
  int AllocatedBits;
  int GOPDquant;

  /* check if the last GOP over uses its budget. If yes, the initial QP of the I frame in 
     the coming  GOP will be increased.*/

  if(R<0)
    Overum=TRUE;
  OverBits=-R;

  /*initialize the lower bound and the upper bound for the target bits of each frame, HRD consideration*/
  LowerBound=(long)(R+bit_rate/frame_rate);
  UpperBound1=(long)(R+InitialDelayOffset);

 /*compute the total number of bits for the current GOP*/ 
  AllocatedBits = (int) floor((1 + np + nb) * bit_rate / frame_rate + 0.5);
  R +=AllocatedBits;
  Np  = np;
  Nb  = nb;

  OverDuantQp=(int)(8*OverBits/AllocatedBits+0.5);
  GOPOverdue=FALSE;
  
  /*field coding*/
  img->IFLAG=1;

  /*Compute InitialQp for each GOP*/
  TotalPFrame=np;
  img->NumberofGOP++;
  if(img->NumberofGOP==1)
  {
    MyInitialQp=input->SeinitialQP;
    PreviousQp2=MyInitialQp-1; //recent change -0;
    QPLastGOP=MyInitialQp;
  
  }
  else
  {
    /*adaptive field/frame coding*/
    if((input->PicInterlace==ADAPTIVE_CODING)\
      ||(input->MbInterlace))
    {
      if (img->FieldFrame == 1)
      {
        img->TotalQpforPPicture += FrameQPBuffer;
        QPLastPFrame = FrameQPBuffer;
      }
      else
      {
        img->TotalQpforPPicture += FieldQPBuffer;
        QPLastPFrame = FieldQPBuffer;
      }
      
    }
    /*compute the average QP of P frames in the previous GOP*/
    PAverageQp=(int)(1.0*img->TotalQpforPPicture/img->NumberofPPicture+0.5);

    GOPDquant=(int)(0.5+1.0*(np+nb+1)/15);
    if(GOPDquant>2)
        GOPDquant=2;

    PAverageQp-=GOPDquant;

    if (PAverageQp > (QPLastPFrame - 2))
      PAverageQp--;
    PAverageQp = MAX(QPLastGOP-2,  PAverageQp);
    PAverageQp = MIN(QPLastGOP+2, PAverageQp);
    PAverageQp = MIN(RC_MAX_QUANT, PAverageQp);
    PAverageQp = MAX(RC_MIN_QUANT, PAverageQp);
  

    MyInitialQp=PAverageQp;
    QPLastGOP = MyInitialQp;
    Pm_Qp=PAverageQp;
    PAveFrameQP=PAverageQp;
    PreviousQp1=PreviousQp2;
    PreviousQp2=MyInitialQp-1;  
  }

  img->TotalQpforPPicture=0;
  img->NumberofPPicture=0;
  NumberofBFrames=0; 
}


/*! 
 *************************************************************************************
 * \brief
 *    Initialize one picture
 *
 *************************************************************************************
*/
void rc_init_pict(int fieldpic,int topfield,int targetcomputation)
{
  int i;

  /* compute the total number of basic units in a frame */
  if(input->MbInterlace)
    TotalNumberofBasicUnit=img->Frame_Total_Number_MB/img->BasicUnit;
  img->NumberofCodedMacroBlocks=0;

  /* Normally, the bandwidth for the VBR case is estimated by 
     a congestion control algorithm. A bandwidth curve can be predefined if we only want to 
     test the proposed algorithm */
  if(input->channel_type==1)
  {
    if(img->NumberofCodedPFrame==58)
      bit_rate *=1.5;
    else if(img->NumberofCodedPFrame==59)
      PreviousBit_Rate=bit_rate;
  }

  /* predefine a target buffer level for each frame */
  if((fieldpic||topfield)&&targetcomputation)
  {
    switch (img->type)
    {
      case P_SLICE:
      /* Since the available bandwidth may vary at any time, the total number of 
         bits is updated picture by picture*/
        if(PreviousBit_Rate!=bit_rate)
          R +=(int) floor((bit_rate-PreviousBit_Rate)*(Np+Nb)/frame_rate+0.5);
              
        /* predefine the  target buffer level for each picture.
           frame layer rate control */
        if(img->BasicUnit==img->Frame_Total_Number_MB)
        {
          if(img->NumberofPPicture==1)
          {
            TargetBufferLevel=CurrentBufferFullness;
            DeltaP=(CurrentBufferFullness-GOPTargetBufferLevel)/(TotalPFrame-1);
            TargetBufferLevel -=DeltaP;
          }
          else if(img->NumberofPPicture>1)
            TargetBufferLevel -=DeltaP;
        }
        /* basic unit layer rate control */
        else
        {
          if(img->NumberofCodedPFrame>0)
          {
            /* adaptive frame/filed coding */
            if(((input->PicInterlace==ADAPTIVE_CODING)||(input->MbInterlace))\
              &&(img->FieldControl==1))
            {
              for(i=0;i<TotalNumberofBasicUnit;i++)
                FCBUPFMAD[i]=FCBUCFMAD[i];
            }
            else
            {
              for(i=0;i<TotalNumberofBasicUnit;i++)
                BUPFMAD[i]=BUCFMAD[i];
            }     
          }

          if(img->NumberofGOP==1)
          {
            if(img->NumberofPPicture==1)
            {
              TargetBufferLevel=CurrentBufferFullness;
              DeltaP=(CurrentBufferFullness-GOPTargetBufferLevel)/(TotalPFrame-1);
              TargetBufferLevel -=DeltaP;
            }
            else if(img->NumberofPPicture>1)
              TargetBufferLevel -=DeltaP;
          }
          else if(img->NumberofGOP>1)
          {
            if(img->NumberofPPicture==0)
            {
              TargetBufferLevel=CurrentBufferFullness;
              DeltaP=(CurrentBufferFullness-GOPTargetBufferLevel)/TotalPFrame;
              TargetBufferLevel -=DeltaP;
            }
            else if(img->NumberofPPicture>0)
              TargetBufferLevel -=DeltaP;
          }
        }

        if(img->NumberofCodedPFrame==1)
          AWp=Wp;
        if((img->NumberofCodedPFrame<8)&&(img->NumberofCodedPFrame>1))
            AWp=Wp*(img->NumberofCodedPFrame-1)/img->NumberofCodedPFrame+\
              AWp/img->NumberofCodedPFrame;
          else if(img->NumberofCodedPFrame>1)
            AWp=Wp/8+7*AWp/8;
          
        // compute the average complexity of B frames
        if(input->successive_Bframe>0)
        {
          // compute the target buffer level
          TargetBufferLevel +=(AWp*(input->successive_Bframe+1)*bit_rate\
            /(frame_rate*(AWp+AWb*input->successive_Bframe))-bit_rate/frame_rate);
        }
        
        break;

         case B_SLICE:
         /* update the total number of bits if the bandwidth is changed*/
           if(PreviousBit_Rate!=bit_rate)
             R +=(int) floor((bit_rate-PreviousBit_Rate)*(Np+Nb)/frame_rate+0.5);
            if((img->NumberofCodedPFrame==1)&&(img->NumberofCodedBFrame==1))
          {
            AWp=Wp;
            AWb=Wb;
          }
          else if(img->NumberofCodedBFrame>1)
          {
            //compute the average weight
            if(img->NumberofCodedBFrame<8)
              AWb=Wb*(img->NumberofCodedBFrame-1)/img->NumberofCodedBFrame+\
                AWb/img->NumberofCodedBFrame;
            else
              AWb=Wb/8+7*AWb/8;
          }

            break;
    }
     /* Compute the target bit for each frame */
    if(img->type==P_SLICE)
    {
      /* frame layer rate control */
      if(img->BasicUnit==img->Frame_Total_Number_MB)
      {
        if(img->NumberofCodedPFrame>0)
        {
          T = (long) floor(Wp*R/(Np*Wp+Nb*Wb) + 0.5);
                
          T1 = (long) floor(bit_rate/frame_rate-GAMMAP*(CurrentBufferFullness-TargetBufferLevel)+0.5);
          T1=MAX(0,T1);
          T = (long)(floor(BETAP*T+(1.0-BETAP)*T1+0.5));
        }
       }
      /* basic unit layer rate control */
      else
      {
        if((img->NumberofGOP==1)&&(img->NumberofCodedPFrame>0))
        {
          T = (int) floor(Wp*R/(Np*Wp+Nb*Wb) + 0.5);
          T1 = (int) floor(bit_rate/frame_rate-GAMMAP*(CurrentBufferFullness-TargetBufferLevel)+0.5);
          T1=MAX(0,T1);
          T = (int)(floor(BETAP*T+(1.0-BETAP)*T1+0.5));
        }
        else if(img->NumberofGOP>1)
        {
          T = (long) floor(Wp*R/(Np*Wp+Nb*Wb) + 0.5);
          T1 = (long) floor(bit_rate/frame_rate-GAMMAP*(CurrentBufferFullness-TargetBufferLevel)+0.5);
          T1 = MAX(0,T1);
          T = (long)(floor(BETAP*T+(1.0-BETAP)*T1+0.5));
        }
      }

      /* reserve some bits for smoothing */

      T=(long)((1.0-0.0*input->successive_Bframe)*T);
      /* HRD consideration */
      T = MAX(T, (long) LowerBound);
        T = MIN(T, (long) UpperBound2);

      if((topfield)||(fieldpic&&((input->PicInterlace==ADAPTIVE_CODING)\
        ||(input->MbInterlace))))
        T_field=T;
    }
  }

  if(fieldpic||topfield)
  {
    /* frame layer rate control */
    img->NumberofHeaderBits=0;
    img->NumberofTextureBits=0;

    /* basic unit layer rate control */
    if(img->BasicUnit<img->Frame_Total_Number_MB)
    {
      TotalFrameQP=0;
      img->NumberofBasicUnitHeaderBits=0;
      img->NumberofBasicUnitTextureBits=0;
      img->TotalMADBasicUnit=0;
      if(img->FieldControl==0)
        NumberofBasicUnit=TotalNumberofBasicUnit;
      else
        NumberofBasicUnit=TotalNumberofBasicUnit/2;
    }
  }
    
  if((img->type==P_SLICE)&&(img->BasicUnit<img->Frame_Total_Number_MB)\
    &&(img->FieldControl==1))
  {
  /* top filed at basic unit layer rate control */
    if(topfield)
    {
      bits_topfield=0;
      T=(long)(T_field*0.6);
    }
  /* bottom filed at basic unit layer rate control */
    else
    {
      T=T_field-bits_topfield;
      img->NumberofBasicUnitHeaderBits=0;
      img->NumberofBasicUnitTextureBits=0;
      img->TotalMADBasicUnit=0;
      NumberofBasicUnit=TotalNumberofBasicUnit/2;
    }
  }
}


/*! 
 *************************************************************************************
 * \brief
 *    calculate MAD for the current macroblock 
 *
 * \return
 *    calculated MAD
 *
 *************************************************************************************
*/
double calc_MAD()
{
  int k,l;
    int s = 0;
  double MAD;

  for (k = 0; k < 16; k++)
    for (l = 0; l < 16; l++)
      s+= abs(diffy[k][l]);
  
  MAD=s*1.0/256;
  return MAD;
}


/*! 
 *************************************************************************************
 * \brief
 *    update one picture after frame/field encoding
 *
 * \param nbits
 *    number of bits used for picture
 *
 *************************************************************************************
*/
void rc_update_pict(int nbits)
{
  R-= nbits; /* remaining # of bits in GOP */
  CurrentBufferFullness += nbits - bit_rate/frame_rate;

  /*update the lower bound and the upper bound for the target bits of each frame, HRD consideration*/
  LowerBound  +=(long)(bit_rate/frame_rate-nbits);
  UpperBound1 +=(long)(bit_rate/frame_rate-nbits);
  UpperBound2 = (long)(OMEGA*UpperBound1);
  
  return;
}


/*! 
 *************************************************************************************
 * \brief
 *    update after frame encoding
 *
 * \param nbits
 *    number of bits used for frame
 *
 *************************************************************************************
*/
void rc_update_pict_frame(int nbits)
{

  /* update the complexity weight of I, P, B frame */
  int Avem_Qc;
  int X=0;
    
  /* frame layer rate control */
  if(img->BasicUnit==img->Frame_Total_Number_MB)
    X = (int) floor(nbits*m_Qc+ 0.5);
  /* basic unit layer rate control */
  else
  {
    if(img->type==P_SLICE)
    {
      if(((img->IFLAG==0)&&(img->FieldControl==1))\
        ||(img->FieldControl==0))
      {
        Avem_Qc=TotalFrameQP/TotalNumberofBasicUnit;
        X=(int)floor(nbits*Avem_Qc+0.5);
      }
    }
    else if(img->type==B_SLICE)
      X = (int) floor(nbits*m_Qc+ 0.5);
  }


  switch (img->type)
  {
  case P_SLICE:
    /* field coding */
    if(((img->IFLAG==0)&&(img->FieldControl==1))\
      ||(img->FieldControl==0))
    {
      Xp = X;
      Np--;
      Wp=Xp;
      Pm_Hp=img->NumberofHeaderBits;
      img->NumberofCodedPFrame++;
      img->NumberofPPicture++;
    }
    else if((img->IFLAG!=0)&&(img->FieldControl==1))
      img->IFLAG=0;
    break;
  case B_SLICE:
    Xb = X;
    Nb--;
    Wb=Xb/THETA; 
    
    img->NumberofCodedBFrame++;
    NumberofBFrames++;
    
    break;
  }
}

/*! 
 *************************************************************************************
 * \brief
 *    coded bits for top field
 *
 * \param nbits
 *    number of bits used for top field
 *
 *************************************************************************************
*/
void setbitscount(int nbits)
{
  bits_topfield = nbits;
}


/*! 
 *************************************************************************************
 * \brief
 *    compute a  quantization parameter for each frame
 *
 *************************************************************************************
*/
int updateQuantizationParameter(int topfield)
{
  double dtmp;
  int m_Bits;
  int BFrameNumber;
  int StepSize;
  int PAverageQP;
  int SumofBasicUnit;
  int i;
  
  /* frame layer rate control */
  if(img->BasicUnit==img->Frame_Total_Number_MB)
  {
    /* fixed quantization parameter is used to coded I frame, the first P frame and the first B frame
    the quantization parameter is adjusted according the available channel bandwidth and 
    the type of vide */  
    /*top field*/
    if((topfield)||(img->FieldControl==0))
    {
      if(img->type==I_SLICE)
      {
        m_Qc=MyInitialQp;
        return m_Qc;
      }
      else if(img->type==B_SLICE)
      {
        if(input->successive_Bframe==1)
        {
            if((input->PicInterlace==ADAPTIVE_CODING)\
              ||(input->MbInterlace))
            {
              if(img->FieldControl==0)
              {                   
                /*previous choice is frame coding*/
                if(img->FieldFrame==1)
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FrameQPBuffer;
                }           
                /*previous choice is field coding*/
                else
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FieldQPBuffer;
                }
              }
            }
/*
          if(PreviousQp1==PreviousQp2)
            m_Qc=PreviousQp1+2;
          else
            m_Qc=(PreviousQp1+PreviousQp2)/2+1;
            */
          m_Qc = max(max(min(PreviousQp1,PreviousQp2) + 2, max(PreviousQp1,PreviousQp2)), PreviousQp2 + 1);

          m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
          m_Qc = MAX(RC_MIN_QUANT, m_Qc);//clipping
        }
        else
        {
          BFrameNumber=(NumberofBFrames+1)%input->successive_Bframe;
          if(BFrameNumber==0)
            BFrameNumber=input->successive_Bframe;
          
          /*adaptive field/frame coding*/
          if(BFrameNumber==1)
          {
            if((input->PicInterlace==ADAPTIVE_CODING)\
              ||(input->MbInterlace))
            {
              if(img->FieldControl==0)
              {
                /*previous choice is frame coding*/
                if(img->FieldFrame==1)
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FrameQPBuffer;
                }
                /*previous choice is field coding*/
                else
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FieldQPBuffer;
                }
              }
            }
          }
          
          if((PreviousQp2-PreviousQp1)<=(-2*input->successive_Bframe-3))
            StepSize=-3;
          else  if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe-2))
            StepSize=-2;
          else if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe-1))
            StepSize=-1;
          else if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe))
            StepSize=0;
          else if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe+1))
            StepSize=1;
          else
            StepSize=2;
          
          m_Qc=PreviousQp1+StepSize;
          m_Qc +=MIN(2*(BFrameNumber-1),MAX(-2*(BFrameNumber-1), \
            (BFrameNumber-1)*(PreviousQp2-PreviousQp1)/(input->successive_Bframe-1)));
          m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
          m_Qc = MAX(RC_MIN_QUANT, m_Qc);//clipping
        }
        return m_Qc;
      }
      else if((img->type==P_SLICE)&&(img->NumberofPPicture==0))
      {
        m_Qc=MyInitialQp;
        
        if(img->FieldControl==0)
        {
          if(active_sps->frame_mbs_only_flag)
          {
            img->TotalQpforPPicture +=m_Qc;
            PreviousQp1=PreviousQp2;
            PreviousQp2=m_Qc;
            Pm_Qp=m_Qc;
          }
          /*adaptive field/frame coding*/
          else
            FrameQPBuffer=m_Qc;
        }
        
        return m_Qc;  
      }
      else
      {
        /*adaptive field/frame coding*/
        if(((input->PicInterlace==ADAPTIVE_CODING)\
          ||(input->MbInterlace))\
          &&(img->FieldControl==0))
        {
          /*previous choice is frame coding*/
          if(img->FieldFrame==1)
          {
            img->TotalQpforPPicture +=FrameQPBuffer;
            Pm_Qp=FrameQPBuffer;
          }
          /*previous choice is field coding*/
          else
          {
            img->TotalQpforPPicture +=FieldQPBuffer;
            Pm_Qp=FieldQPBuffer;
          }
        }
        
        m_X1=Pm_X1;
        m_X2=Pm_X2;
        m_Hp=PPreHeader;
        m_Qp=Pm_Qp;
        DuantQp=PDuantQp;
        MADPictureC1=PMADPictureC1;
        MADPictureC2=PMADPictureC2;
        PreviousPictureMAD=PPictureMAD[0];
        
        /* predict the MAD of current picture*/
        CurrentFrameMAD=MADPictureC1*PreviousPictureMAD+MADPictureC2;
        
        /*compute the number of bits for the texture*/      
        
        if(T<0)
        {
          m_Qc=m_Qp+DuantQp;
          m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
        }
        else
        {
          m_Bits =T-m_Hp;
          m_Bits = MAX(m_Bits, (int)(bit_rate/(MINVALUE*frame_rate)));
          dtmp = CurrentFrameMAD * m_X1 * CurrentFrameMAD * m_X1 \
            + 4 * m_X2 * CurrentFrameMAD * m_Bits;
          if ((m_X2 == 0.0) || (dtmp < 0) || ((sqrt (dtmp) - m_X1 * CurrentFrameMAD) <= 0.0)) // fall back 1st order mode
            m_Qstep = (float) (m_X1 * CurrentFrameMAD / (double) m_Bits);
          else // 2nd order mode
            m_Qstep = (float) ((2 * m_X2 * CurrentFrameMAD) / (sqrt (dtmp) - m_X1 * CurrentFrameMAD));
          
          m_Qc=Qstep2QP(m_Qstep);
          
          m_Qc = MIN(m_Qp+DuantQp,  m_Qc);  // control variation
          m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
          m_Qc = MAX(m_Qp-DuantQp, m_Qc); // control variation
          m_Qc = MAX(RC_MIN_QUANT, m_Qc);
        }
        
        if(img->FieldControl==0)
        {
          /*frame coding*/
          if(active_sps->frame_mbs_only_flag)
          {
            img->TotalQpforPPicture +=m_Qc;
            PreviousQp1=PreviousQp2;
            PreviousQp2=m_Qc;
            Pm_Qp=m_Qc;
          }
          /*adaptive field/frame coding*/
          else
            FrameQPBuffer=m_Qc;
        }
        
        return m_Qc;
      }
   }
   /*bottom field*/
   else
   {
     if((img->type==P_SLICE)&&(img->IFLAG==0))
     {
       /*field coding*/
       if(input->PicInterlace==FIELD_CODING)
       {
         img->TotalQpforPPicture +=m_Qc;
         PreviousQp1=PreviousQp2+1; 
         PreviousQp2=m_Qc;//+0 Recent change 13/1/2003
         Pm_Qp=m_Qc;
       }
       /*adaptive field/frame coding*/
       else
         FieldQPBuffer=m_Qc;     
     }
     return m_Qc;
   }
  }
  /*basic unit layer rate control*/
  else
  {
    /*top filed of I frame*/
    if(img->type==I_SLICE)
    {
      m_Qc=MyInitialQp;
      return m_Qc;
    }
    /*bottom field of I frame*/
    else if((img->type==P_SLICE)&&(img->IFLAG==1)&&(img->FieldControl==1))
    {
      m_Qc=MyInitialQp;
      return m_Qc;
    }
    else if(img->type==B_SLICE)
    {
      /*top filed of B frame*/
      if((topfield)||(img->FieldControl==0))
      {
        if(input->successive_Bframe==1)
        {
         /*adaptive field/frame coding*/
          if((input->PicInterlace==ADAPTIVE_CODING)\
              ||(input->MbInterlace))
            {
              if(img->FieldControl==0)
              {             
                /*previous choice is frame coding*/
                if(img->FieldFrame==1)
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FrameQPBuffer;
                }
                /*previous choice is field coding*/
                else
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FieldQPBuffer;
                }
              }
            }

          if(PreviousQp1==PreviousQp2)
            m_Qc=PreviousQp1+2;
          else
            m_Qc=(PreviousQp1+PreviousQp2)/2+1;
          m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
          m_Qc = MAX(RC_MIN_QUANT, m_Qc);//clipping
        }
        else
        {
          BFrameNumber=(NumberofBFrames+1)%input->successive_Bframe;
          if(BFrameNumber==0)
            BFrameNumber=input->successive_Bframe;
          
          /*adaptive field/frame coding*/
          if(BFrameNumber==1)
          {
            if((input->PicInterlace==ADAPTIVE_CODING)\
              ||(input->MbInterlace))
            {
              if(img->FieldControl==0)
              {
                /*previous choice is frame coding*/
                if(img->FieldFrame==1)
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FrameQPBuffer;
                }
                /*previous choice is field coding*/
                else
                {
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=FieldQPBuffer;
                }
              } 
            }
          }
          
          if((PreviousQp2-PreviousQp1)<=(-2*input->successive_Bframe-3))
            StepSize=-3;
          else  if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe-2))
            StepSize=-2;
          else if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe-1))
            StepSize=-1;
          else if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe))
            StepSize=0;//0
          else if((PreviousQp2-PreviousQp1)==(-2*input->successive_Bframe+1))
            StepSize=1;//1
          else
            StepSize=2;//2
          m_Qc=PreviousQp1+StepSize;
          m_Qc +=MIN(2*(BFrameNumber-1),MAX(-2*(BFrameNumber-1), \
            (BFrameNumber-1)*(PreviousQp2-PreviousQp1)/(input->successive_Bframe-1)));
          m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
          m_Qc = MAX(RC_MIN_QUANT, m_Qc);//clipping
        }
        return m_Qc;
      }
      /*bottom field of B frame*/
      else
        return m_Qc;
    }
    else if(img->type==P_SLICE)
    {
      if((img->NumberofGOP==1)&&(img->NumberofPPicture==0))
      {
        if((img->FieldControl==0)||((img->FieldControl==1)\
          &&(img->IFLAG==0)))
        {
          /*top field of the first P frame*/
          m_Qc=MyInitialQp;
          img->NumberofBasicUnitHeaderBits=0;
          img->NumberofBasicUnitTextureBits=0;
          NumberofBasicUnit--;
          /*bottom field of the first P frame*/
          if((!topfield)&&(NumberofBasicUnit==0))
          {
            /*frame coding or field coding*/
            if((active_sps->frame_mbs_only_flag)||(input->PicInterlace==FIELD_CODING))
            {
              img->TotalQpforPPicture +=m_Qc;
              PreviousQp1=PreviousQp2;
              PreviousQp2=m_Qc;
              PAveFrameQP=m_Qc;
              PAveHeaderBits3=PAveHeaderBits2;
            }
            /*adaptive frame/field coding*/
            else if((input->PicInterlace==ADAPTIVE_CODING)\
              ||(input->MbInterlace))
            {
              if(img->FieldControl==0)
              {
                FrameQPBuffer=m_Qc;
                FrameAveHeaderBits=PAveHeaderBits2;
              }
              else
              {
                FieldQPBuffer=m_Qc;
                FieldAveHeaderBits=PAveHeaderBits2;
              }
            }
          }
          Pm_Qp=m_Qc;
          TotalFrameQP +=m_Qc;
          return m_Qc;
        }
      }
      else
      {
        m_X1=Pm_X1;
        m_X2=Pm_X2;
        m_Hp=PPreHeader;
        m_Qp=Pm_Qp;
        DuantQp=PDuantQp;
        MADPictureC1=PMADPictureC1;
        MADPictureC2=PMADPictureC2;

        if(img->FieldControl==0)
          SumofBasicUnit=TotalNumberofBasicUnit;
        else
          SumofBasicUnit=TotalNumberofBasicUnit/2;

        /*the average QP of the previous frame is used to coded the first basic unit of the current frame or field*/
        if(NumberofBasicUnit==SumofBasicUnit)
        {

          /*adaptive field/frame coding*/
          if(((input->PicInterlace==ADAPTIVE_CODING)\
            ||(input->MbInterlace))\
            &&(img->FieldControl==0))
          {
            /*previous choice is frame coding*/
            if(img->FieldFrame==1)
            {
              if(img->NumberofPPicture>0)
                img->TotalQpforPPicture +=FrameQPBuffer;
              PAveFrameQP=FrameQPBuffer;
              PAveHeaderBits3=FrameAveHeaderBits;
            }       
            /*previous choice is field coding*/
            else
            {
              if(img->NumberofPPicture>0)
                img->TotalQpforPPicture +=FieldQPBuffer;
              PAveFrameQP=FieldQPBuffer;
              PAveHeaderBits3=FieldAveHeaderBits;
            }
          }

          if(T<=0)
          {
            m_Qc=PAveFrameQP+2;
            if(m_Qc>RC_MAX_QUANT)
              m_Qc=RC_MAX_QUANT;
            if(topfield||(img->FieldControl==0))
              GOPOverdue=TRUE;
          }
          else
          {
            m_Qc=PAveFrameQP; 
          }
          TotalFrameQP +=m_Qc;
          NumberofBasicUnit--;
          Pm_Qp=PAveFrameQP;
          return m_Qc;
        }else
        {
          /*compute the number of remaining bits*/
          TotalBasicUnitBits=img->NumberofBasicUnitHeaderBits+img->NumberofBasicUnitTextureBits;
          T -=TotalBasicUnitBits;
          img->NumberofBasicUnitHeaderBits=0;
          img->NumberofBasicUnitTextureBits=0;
          if(T<0)
          {
            if(GOPOverdue==TRUE)
              m_Qc=m_Qp+2;
            else 
              m_Qc=m_Qp+DDquant;//2 
            m_Qc = MIN(m_Qc, RC_MAX_QUANT);  // clipping
            if(input->basicunit>=MBPerRow)
              m_Qc = MIN(m_Qc, PAveFrameQP+6); 
            else
              m_Qc = MIN(m_Qc, PAveFrameQP+3);
            
            TotalFrameQP +=m_Qc;
            NumberofBasicUnit--;
            if(NumberofBasicUnit==0)
            {
              if((!topfield)||(img->FieldControl==0))
              {
                /*frame coding or field coding*/
                if((active_sps->frame_mbs_only_flag)||(input->PicInterlace==FIELD_CODING))
                {
                  PAverageQP=(int)(1.0*TotalFrameQP/TotalNumberofBasicUnit+0.5);
                  if (img->NumberofPPicture == (input->intra_period - 2))
                    QPLastPFrame = PAverageQP;
                  
                  img->TotalQpforPPicture +=PAverageQP;
                  if(GOPOverdue==TRUE)
                  {
                    PreviousQp1=PreviousQp2+1;
                    PreviousQp2=PAverageQP;                   
                  }
                  else
                  {
                    if((img->NumberofPPicture==0)&&(img->NumberofGOP>1))
                    {
                      PreviousQp1=PreviousQp2;
                      PreviousQp2=PAverageQP;
                    }
                    else if(img->NumberofPPicture>0)
                    {
                      PreviousQp1=PreviousQp2+1;
                      PreviousQp2=PAverageQP;
                    }
                  }
                  PAveFrameQP=PAverageQP;
                  PAveHeaderBits3=PAveHeaderBits2;
                }
                /*adaptive field/frame coding*/
                else if((input->PicInterlace==ADAPTIVE_CODING)\
                  ||(input->MbInterlace))
                {
                  if(img->FieldControl==0)
                  {
                    PAverageQP=(int)(1.0*TotalFrameQP/TotalNumberofBasicUnit+0.5);
                    FrameQPBuffer=PAverageQP;
                    FrameAveHeaderBits=PAveHeaderBits2;
                  }
                  else
                  {
                    PAverageQP=(int)(1.0*TotalFrameQP/TotalNumberofBasicUnit+0.5);
                    FieldQPBuffer=PAverageQP;
                    FieldAveHeaderBits=PAveHeaderBits2;
                  }
                }
              }
            }
            if(GOPOverdue==TRUE)
              Pm_Qp=PAveFrameQP;
            else
              Pm_Qp=m_Qc;
            return m_Qc;
          }
          else
          {
            /*predict the MAD of current picture*/
            if(((input->PicInterlace==ADAPTIVE_CODING)||(input->MbInterlace))\
              &&(img->FieldControl==1))
            {
              CurrentFrameMAD=MADPictureC1*FCBUPFMAD[TotalNumberofBasicUnit-NumberofBasicUnit]+MADPictureC2;
              TotalBUMAD=0;
              for(i=TotalNumberofBasicUnit-1; i>=(TotalNumberofBasicUnit-NumberofBasicUnit);i--)
              {
                CurrentBUMAD=MADPictureC1*FCBUPFMAD[i]+MADPictureC2;
                TotalBUMAD +=CurrentBUMAD*CurrentBUMAD;
              }
            }
            else
            {
              CurrentFrameMAD=MADPictureC1*BUPFMAD[TotalNumberofBasicUnit-NumberofBasicUnit]+MADPictureC2;
              TotalBUMAD=0;
              for(i=TotalNumberofBasicUnit-1; i>=(TotalNumberofBasicUnit-NumberofBasicUnit);i--)
              {
                CurrentBUMAD=MADPictureC1*BUPFMAD[i]+MADPictureC2;
                TotalBUMAD +=CurrentBUMAD*CurrentBUMAD;
              }
            }
            
            /*compute the total number of bits for the current basic unit*/
            m_Bits =(int)(T*CurrentFrameMAD*CurrentFrameMAD/TotalBUMAD);
            /*compute the number of texture bits*/
            m_Bits -=PAveHeaderBits2;
            
            m_Bits=MAX(m_Bits,(int)(bit_rate/(MINVALUE*frame_rate*TotalNumberofBasicUnit)));
            
            dtmp = CurrentFrameMAD * m_X1 * CurrentFrameMAD * m_X1 \
              + 4 * m_X2 * CurrentFrameMAD * m_Bits;
            if ((m_X2 == 0.0) || (dtmp < 0) || ((sqrt (dtmp) - m_X1 * CurrentFrameMAD) <= 0.0))  // fall back 1st order mode
              m_Qstep = (float)(m_X1 * CurrentFrameMAD / (double) m_Bits);
            else // 2nd order mode
              m_Qstep = (float) ((2 * m_X2 * CurrentFrameMAD) / (sqrt (dtmp) - m_X1 * CurrentFrameMAD));
            
            m_Qc=Qstep2QP(m_Qstep);
            m_Qc = MIN(m_Qp+DDquant,  m_Qc); // control variation
            
            if(input->basicunit>=MBPerRow)
              m_Qc = MIN(PAveFrameQP+6, m_Qc);
            else
              m_Qc = MIN(PAveFrameQP+3, m_Qc);
            
            m_Qc = MIN(m_Qc, RC_MAX_QUANT);  // clipping
            m_Qc = MAX(m_Qp-DDquant, m_Qc);  // control variation 
            if(input->basicunit>=MBPerRow)
              m_Qc = MAX(PAveFrameQP-6, m_Qc);
            else
              m_Qc = MAX(PAveFrameQP-3, m_Qc);
            
            m_Qc = MAX(RC_MIN_QUANT, m_Qc);
            TotalFrameQP +=m_Qc;
            Pm_Qp=m_Qc;
            NumberofBasicUnit--;
            if((NumberofBasicUnit==0)&&(img->type==P_SLICE))
            {
              if((!topfield)||(img->FieldControl==0))
              {
                /*frame coding or field coding*/
                if((active_sps->frame_mbs_only_flag)||(input->PicInterlace==FIELD_CODING))
                {
                  PAverageQP=(int)(1.0*TotalFrameQP/TotalNumberofBasicUnit+0.5);
                  if (img->NumberofPPicture == (input->intra_period - 2))
                    QPLastPFrame = PAverageQP;

                  img->TotalQpforPPicture +=PAverageQP;
                  PreviousQp1=PreviousQp2;
                  PreviousQp2=PAverageQP; 
                  PAveFrameQP=PAverageQP;
                  PAveHeaderBits3=PAveHeaderBits2;
                }
                else if((input->PicInterlace==ADAPTIVE_CODING)\
                  ||(input->MbInterlace))
                {
                  if(img->FieldControl==0)
                  {
                    PAverageQP=(int)(1.0*TotalFrameQP/TotalNumberofBasicUnit+0.5);
                    FrameQPBuffer=PAverageQP;
                    FrameAveHeaderBits=PAveHeaderBits2;
                  }
                  else
                  {
                    PAverageQP=(int)(1.0*TotalFrameQP/TotalNumberofBasicUnit+0.5);
                    FieldQPBuffer=PAverageQP;
                    FieldAveHeaderBits=PAveHeaderBits2;
                  }
                }
              }
            }
            return m_Qc;
          }
        }
      }
    } 
  }
  return m_Qc;
}


/*! 
 *************************************************************************************
 * \brief
 *    update the parameters of quadratic R-D model
 *
 *************************************************************************************
*/
void updateRCModel ()
{

  int n_windowSize;
  int i;
  double error[20], std = 0.0, threshold;
  int m_Nc;
  Boolean MADModelFlag = FALSE;

  if(img->type==P_SLICE)
  {
    /*frame layer rate control*/
    if(img->BasicUnit==img->Frame_Total_Number_MB)
    {
      CurrentFrameMAD=ComputeFrameMAD();
      m_Nc=img->NumberofCodedPFrame;
    }
    /*basic unit layer rate control*/
    else
    {
      /*compute the MAD of the current basic unit*/
      if((input->MbInterlace)&&(img->FieldControl==0))
        CurrentFrameMAD=img->TotalMADBasicUnit/img->BasicUnit/2;
      else
        CurrentFrameMAD=img->TotalMADBasicUnit/img->BasicUnit;
      
      
      img->TotalMADBasicUnit=0;
              
      /* compute the average number of header bits*/
      
      CodedBasicUnit=TotalNumberofBasicUnit-NumberofBasicUnit;
      if(CodedBasicUnit>0)
      {
        PAveHeaderBits1=(int)(1.0*(PAveHeaderBits1*(CodedBasicUnit-1)+\
          +img->NumberofBasicUnitHeaderBits)/CodedBasicUnit+0.5);
        if(PAveHeaderBits3==0)
          PAveHeaderBits2=PAveHeaderBits1;
        else
          PAveHeaderBits2=(int)(1.0*(PAveHeaderBits1*CodedBasicUnit+\
          +PAveHeaderBits3*NumberofBasicUnit)/TotalNumberofBasicUnit+0.5);
      }
      /*update the record of MADs for reference*/
      if(((input->PicInterlace==ADAPTIVE_CODING)||(input->MbInterlace))\
        &&(img->FieldControl==1))
        FCBUCFMAD[TotalNumberofBasicUnit-1-NumberofBasicUnit]=CurrentFrameMAD;
      else
        BUCFMAD[TotalNumberofBasicUnit-1-NumberofBasicUnit]=CurrentFrameMAD;
      
      if(NumberofBasicUnit!=0)
        m_Nc=img->NumberofCodedPFrame*TotalNumberofBasicUnit+CodedBasicUnit;
      else
        m_Nc=(img->NumberofCodedPFrame-1)*TotalNumberofBasicUnit+CodedBasicUnit;
      
    }
    
    if(m_Nc>1)
      MADModelFlag=TRUE;
    
    PPreHeader=img->NumberofHeaderBits;
    for (i = 19; i > 0; i--) 
    {// update the history
      Pm_rgQp[i] = Pm_rgQp[i - 1];
      m_rgQp[i]=Pm_rgQp[i];
      Pm_rgRp[i] = Pm_rgRp[i - 1];
      m_rgRp[i]=Pm_rgRp[i];
    }
    Pm_rgQp[0] = QP2Qstep(m_Qc); //*1.0/CurrentFrameMAD;
    /*frame layer rate control*/
    if(img->BasicUnit==img->Frame_Total_Number_MB)
      Pm_rgRp[0] = img->NumberofTextureBits*1.0/CurrentFrameMAD;
    /*basic unit layer rate control*/
    else
      Pm_rgRp[0]=img->NumberofBasicUnitTextureBits*1.0/CurrentFrameMAD;
    
    m_rgQp[0]=Pm_rgQp[0];
    m_rgRp[0]=Pm_rgRp[0];
    m_X1=Pm_X1;
    m_X2=Pm_X2;
    
    
    /*compute the size of window*/
    n_windowSize = (CurrentFrameMAD>PreviousFrameMAD)?(int)(PreviousFrameMAD/CurrentFrameMAD*20)\
                   :(int)(CurrentFrameMAD/PreviousFrameMAD*20);
    n_windowSize=MAX(n_windowSize, 1);
    n_windowSize=MIN(n_windowSize,m_Nc);
    n_windowSize=MIN(n_windowSize,m_windowSize+1);
    n_windowSize=MIN(n_windowSize,20);
    
    /*update the previous window size*/
    m_windowSize=n_windowSize;
    
    for (i = 0; i < 20; i++) 
    {
      m_rgRejected[i] = FALSE;
    }
    
    // initial RD model estimator
    RCModelEstimator (n_windowSize);
    
    n_windowSize = m_windowSize;
    // remove outlier 
    
    for (i = 0; i < (int) n_windowSize; i++) 
    {
      error[i] = m_X1 / m_rgQp[i] + m_X2 / (m_rgQp[i] * m_rgQp[i]) - m_rgRp[i];
      std += error[i] * error[i]; 
    }
    threshold = (n_windowSize == 2) ? 0 : sqrt (std / n_windowSize);
    for (i = 0; i < (int) n_windowSize; i++) 
    {
      if (fabs(error[i]) > threshold)
        m_rgRejected[i] = TRUE;
    }
    // always include the last data point
    m_rgRejected[0] = FALSE;
    
    // second RD model estimator
    RCModelEstimator (n_windowSize);
    
    if(MADModelFlag)
      updateMADModel();
    else if(img->type==P_SLICE)
      PPictureMAD[0]=CurrentFrameMAD;
  } 
}

/*! 
 *************************************************************************************
 * \brief
 *    Model Estimator
 *
 *************************************************************************************
*/
void RCModelEstimator (int n_windowSize)
{
  int n_realSize = n_windowSize;
  int i;
  double oneSampleQ = 0;
  double a00 = 0.0, a01 = 0.0, a10 = 0.0, a11 = 0.0, b0 = 0.0, b1 = 0.0;
  double MatrixValue;
  Boolean estimateX2 = FALSE;

  for (i = 0; i < n_windowSize; i++) 
  {// find the number of samples which are not rejected
    if (m_rgRejected[i])
      n_realSize--;
  }

  // default RD model estimation results

  m_X1 = m_X2 = 0.0;

  for (i = 0; i < n_windowSize; i++)  
  {
    if (!m_rgRejected[i])
      oneSampleQ = m_rgQp[i];
  }
  for (i = 0; i < n_windowSize; i++)  
  {// if all non-rejected Q are the same, take 1st order model
    if ((m_rgQp[i] != oneSampleQ) && !m_rgRejected[i])
      estimateX2 = TRUE;
    if (!m_rgRejected[i])
      m_X1 += (m_rgQp[i] * m_rgRp[i]) / n_realSize;
  }

  // take 2nd order model to estimate X1 and X2
  if ((n_realSize >= 1) && estimateX2) 
  {
    for (i = 0; i < n_windowSize; i++) 
    {
      if (!m_rgRejected[i]) 
      {
        a00 = a00 + 1.0;
        a01 += 1.0 / m_rgQp[i];
        a10 = a01;
        a11 += 1.0 / (m_rgQp[i] * m_rgQp[i]);
        b0 += m_rgQp[i] * m_rgRp[i];
        b1 += m_rgRp[i];
      }
    }
    // solve the equation of AX = B
    MatrixValue=a00*a11-a01*a10;
    if(fabs(MatrixValue)>0.000001)
    {
      m_X1=(b0*a11-b1*a01)/MatrixValue;
      m_X2=(b1*a00-b0*a10)/MatrixValue;
    }
    else
    {
      m_X1=b0/a00;
      m_X2=0.0;
    }
    
  }
  if(img->type==P_SLICE)
  {
    Pm_X1=m_X1;
    Pm_X2=m_X2;
  }
}


/*! 
 *************************************************************************************
 * \brief
 *    Compute Frame MAD
 *
 *************************************************************************************
*/
double ComputeFrameMAD()
{
  double TotalMAD;
  int i;
  TotalMAD=0.0;
  for(i=0;i<img->Frame_Total_Number_MB;i++)
    TotalMAD +=img->MADofMB[i];
  TotalMAD /=img->Frame_Total_Number_MB;
  return TotalMAD;
}


/*! 
 *************************************************************************************
 * \brief
 *    update the parameters of linear prediction model
 *
 *************************************************************************************
*/
void updateMADModel ()
{
  
  int n_windowSize;
  int i;
  double error[20], std = 0.0, threshold;
  int m_Nc;
  
  if(img->NumberofCodedPFrame>0)
  {
    //assert (img->type!=P_SLICE);
    
    /*frame layer rate control*/
    if(img->BasicUnit==img->Frame_Total_Number_MB)
      m_Nc=img->NumberofCodedPFrame;
    /*basic unit layer rate control*/
    else
      m_Nc=img->NumberofCodedPFrame*TotalNumberofBasicUnit+CodedBasicUnit;
    
    for (i = 19; i > 0; i--) 
    {// update the history
      PPictureMAD[i] = PPictureMAD[i - 1];
      PictureMAD[i]=PPictureMAD[i];
      ReferenceMAD[i]= ReferenceMAD[i-1];
    }
    PPictureMAD[0] = CurrentFrameMAD;
    PictureMAD[0]=PPictureMAD[0];
    if(img->BasicUnit==img->Frame_Total_Number_MB)
      ReferenceMAD[0]=PictureMAD[1];
    else
    {
      if(((input->PicInterlace==ADAPTIVE_CODING)||(input->MbInterlace))\
        &&(img->FieldControl==1))
        ReferenceMAD[0]=FCBUPFMAD[TotalNumberofBasicUnit-1-NumberofBasicUnit];
      else
        ReferenceMAD[0]=BUPFMAD[TotalNumberofBasicUnit-1-NumberofBasicUnit];
    }
    MADPictureC1=PMADPictureC1;
    MADPictureC2=PMADPictureC2;
    
    
    /*compute the size of window*/
    
    n_windowSize = (CurrentFrameMAD>PreviousFrameMAD)?(int)(PreviousFrameMAD/CurrentFrameMAD*20)\
      :(int)(CurrentFrameMAD/PreviousFrameMAD*20);
    n_windowSize=MIN(n_windowSize,(m_Nc-1));
    n_windowSize=MAX(n_windowSize, 1);
    n_windowSize=MIN(n_windowSize,MADm_windowSize+1);
    n_windowSize=MIN(20,n_windowSize);
    /*update the previous window size*/
    MADm_windowSize=n_windowSize;
    
    for (i = 0; i < 20; i++) 
    {
      PictureRejected[i] = FALSE;
    }
    //update the MAD for the previous frame
    if(img->type==P_SLICE)
      PreviousFrameMAD=CurrentFrameMAD;
    
    // initial MAD model estimator
    MADModelEstimator (n_windowSize);
    
    // remove outlier 
    
    for (i = 0; i < (int) n_windowSize; i++) 
    {
      error[i] = MADPictureC1*ReferenceMAD[i]+MADPictureC2-PictureMAD[i];
      std += error[i] * error[i]; 
    }
    threshold = (n_windowSize == 2) ? 0 : sqrt (std / n_windowSize);
    for (i = 0; i < (int) n_windowSize; i++) 
    {
      if (fabs(error[i]) > threshold)
        PictureRejected[i] = TRUE;
    }
    // always include the last data point
    PictureRejected[0] = FALSE;
    
    // second MAD model estimator
    MADModelEstimator (n_windowSize);
  }
}


/*! 
 *************************************************************************************
 * \brief
 *    MAD mode estimator
 *
 *************************************************************************************
*/
void MADModelEstimator (int n_windowSize)
{
  int n_realSize = n_windowSize;
  int i;
  double oneSampleQ = 0;
  double a00 = 0.0, a01 = 0.0, a10 = 0.0, a11 = 0.0, b0 = 0.0, b1 = 0.0;
  double MatrixValue;
  Boolean estimateX2 = FALSE;
  
  for (i = 0; i < n_windowSize; i++) 
  {// find the number of samples which are not rejected
    if (PictureRejected[i])
      n_realSize--;
  }
  
  // default MAD model estimation results
  
  MADPictureC1 = MADPictureC2 = 0.0;
  
  for (i = 0; i < n_windowSize; i++)  
  {
    if (!PictureRejected[i])
      oneSampleQ = PictureMAD[i];
  }

  for (i = 0; i < n_windowSize; i++)  
  {// if all non-rejected MAD are the same, take 1st order model
    if ((PictureMAD[i] != oneSampleQ) && !PictureRejected[i])
      estimateX2 = TRUE;
    if (!PictureRejected[i])
      MADPictureC1 += PictureMAD[i] / (ReferenceMAD[i]*n_realSize);
  }
  
  // take 2nd order model to estimate X1 and X2
  if ((n_realSize >= 1) && estimateX2) 
  {
    for (i = 0; i < n_windowSize; i++) 
    {
      if (!PictureRejected[i]) 
      {
        a00 = a00 + 1.0;
        a01 += ReferenceMAD[i];
        a10 = a01;
        a11 += ReferenceMAD[i]*ReferenceMAD[i];
        b0 += PictureMAD[i];
        b1 += PictureMAD[i]*ReferenceMAD[i];
      }
    }
    // solve the equation of AX = B
    MatrixValue=a00*a11-a01*a10;
    if(fabs(MatrixValue)>0.000001)
    {
      MADPictureC2=(b0*a11-b1*a01)/MatrixValue;
      MADPictureC1=(b1*a00-b0*a10)/MatrixValue;
    }
    else
    {
      MADPictureC1=b0/a01;
      MADPictureC2=0.0;
    }
    
  }
  if(img->type==P_SLICE)
  {
    PMADPictureC1=MADPictureC1;
    PMADPictureC2=MADPictureC2;
  }
}


/*! 
 *************************************************************************************
 * \brief
 *    map QP to Qstep
 *
 *************************************************************************************
*/
double QP2Qstep( int QP )
{
  int i; 
  double Qstep;
  static const double QP2QSTEP[6] = { 0.625, 0.6875, 0.8125, 0.875, 1.0, 1.125 };
  
  Qstep = QP2QSTEP[QP % 6];
  for( i=0; i<(QP/6); i++)
    Qstep *= 2;
  
  return Qstep;
}


/*! 
 *************************************************************************************
 * \brief
 *    map Qstep to QP
 *
 *************************************************************************************
*/
int Qstep2QP( double Qstep )
{
  int q_per = 0, q_rem = 0;
  
  //  assert( Qstep >= QP2Qstep(0) && Qstep <= QP2Qstep(51) );
  if( Qstep < QP2Qstep(0))
    return 0;
  else if (Qstep > QP2Qstep(51) )
    return 51;
  
  while( Qstep > QP2Qstep(5) )
  {
    Qstep /= 2;
    q_per += 1;
  }
  
  if (Qstep <= (0.625+0.6875)/2) 
  {
    Qstep = 0.625;
    q_rem = 0;
  }
  else if (Qstep <= (0.6875+0.8125)/2)
  {
    Qstep = 0.6875;
    q_rem = 1;
  }
  else if (Qstep <= (0.8125+0.875)/2)
  {
    Qstep = 0.8125;
    q_rem = 2;
  }
  else if (Qstep <= (0.875+1.0)/2)
  {
    Qstep = 0.875;
    q_rem = 3;
  }
  else if (Qstep <= (1.0+1.125)/2)
  {
    Qstep = 1.0;  
    q_rem = 4;
  }
  else 
  {
    Qstep = 1.125;
    q_rem = 5;
  }
  
  return (q_per * 6 + q_rem);
}
