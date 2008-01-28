/*
 * packet.c - Implementation of the packet interface
 *
 * This file is a part of the NetBench suite by Gokhan Memik
 *
 * This source file is distributed "as is" in the hope that it will be
 * useful.  The suite comes with no warranty, and no author or
 * distributor accepts any responsibility for the consequences of its
 * use. 
 * 
 * You are welcome to use, share and improve this
 * source file.  You are forbidden to forbid anyone else to use, share
 * and improve what you give them.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "packet_lengths.h"
#include "headers.h"
#include "packet.h"

/* Traces automatically drop the TCP checksum and urgent pointer, so header is 36 bytes */
#define HEADER_SIZE 36
int packets_processed = 0;

#ifdef CONSTANT_PACKET
unsigned int packet_index = 0;
#endif

char *
get_next_packet ()
{
  char *packet;
  unsigned int packet_length;
  
  if (packets_processed == MAX_PACKETS)
    {
      fprintf (stderr, "All packets (%d) processed, recompile with larger MAX_PACKETS \n", MAX_PACKETS);
      exit (1);
    }
  
  packet_length = (packet_lengths[packets_processed]);
  if (packet_length < 40)
    {
      /* Should never happen */
      fprintf (stderr, "Packet not large enough, increasing the size\n");
      packet_length = 40;
    }

#ifdef CONSTANT_PACKET
  /* Packets are stored in a continuous chunk in the memory, just change the index... */
  packet = &packets[packet_index];
  packet_index += packet_length;
#else
  /* Have to call malloc to create packet memory */
  if ((packet =  (char *) malloc (packet_length)) == NULL)
    {
      fprintf (stderr, "Not enough space to create packet data \n");
      exit (1);
    }

  /* Copy the header information */
  memcpy ((void *)packet, (void *)headers[packets_processed], HEADER_SIZE);
#endif

  packets_processed ++;
  return packet;
}

/* For debugging purposes, to get the size of the packet_numberth packet */
unsigned int 
packet_size (unsigned int packet_number)
{
  if (packet_number == MAX_PACKETS)
    return (packet_lengths[packets_processed]);
  else return (packet_lengths[packet_number]);
}
