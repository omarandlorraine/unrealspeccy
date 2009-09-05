
#include "dxr_atmf.cpp"
#include "dxr_atm0.cpp"
#include "dxr_atm2.cpp"
#include "dxr_atm6.cpp"
#include "dxr_atm7.cpp"

void rend_atm(unsigned char *dst, unsigned pitch)
{
   if (temp.atm_pal_changed) {
      pixel_tables();
      temp.atm_pal_changed = 0;
   }

   switch (comp.pFF77 & 7)
   {
      case 0:
         rend_atm0(dst, pitch);
         break;
      case 2:
         rend_atm2(dst, pitch);
         break;
      case 3:
         rend_double(dst, pitch);
         break;
      case 6:
         rend_atm6(dst, pitch);
         break;
      case 7:
         rend_atm7(dst, pitch);
         break;
      default:
         // unknown mode
         break;
   }
}
