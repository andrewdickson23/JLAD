///\file
#ifndef __ATTACHMENT_H
#define __ATTACHMENT_H

///Attachment structure to add more customization to the robot class
struct attachment{
   std::string name;///<stores the name of the attachment
   std::string description;///<describes the functionality of the attachment
   int atkm;///<attack modifier
   int hpm;///<health point modifier
   int spdm;///<speed modifier
   int defm;///<defence modifier
   int rngm;///<range of the attachment for offensive attachments only
   int weight;///<weight of the attachment
   int fuelm;///<fuel storage modifier
};

#endif
