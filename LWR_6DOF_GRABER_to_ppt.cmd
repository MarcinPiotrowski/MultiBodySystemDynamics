! 
! This Adams/View command file reads an Adams dataset followed by the 
! SHL files corresponding to each of the parts in the Adams dataset.
! 


default command echo=off
defaults units  &
     length=meter  &
     angle=rad  &
     force=newton  &
     mass=kg  &
     time=sec
defaults attributes size_of_icons=0.050000  


!---------------------------------------------
!     Adams/View model named 'LWR_6DOF_GRABER'
!---------------------------------------------
file adams read file="LWR_6DOF_GRABER.adm"


!-----------------------------
!     Adams/View Geometry
!-----------------------------

!----------------- .LWR_6DOF_GRABER.ground -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.ground  &
     name_visibility=OFF

!----------------- .LWR_6DOF_GRABER.PART_2 -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.PART_2  &
     color=GREEN  &
     name_visibility=OFF

!----------------- .LWR_6DOF_GRABER.PART_3 -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.PART_3  &
     color=MAIZE  &
     name_visibility=OFF

!----------------- .LWR_6DOF_GRABER.PART_4 -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.PART_4  &
     color=CYAN  &
     name_visibility=OFF

!----------------- .LWR_6DOF_GRABER.PART_5 -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.PART_5  &
     color=MAGENTA  &
     name_visibility=OFF

!----------------- .LWR_6DOF_GRABER.PART_6 -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.PART_6  &
     color=RED  &
     name_visibility=OFF

!----------------- .LWR_6DOF_GRABER.PART_7 -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.PART_7  &
     color=GREEN  &
     name_visibility=OFF

!----------------- .LWR_6DOF_GRABER.GRABER -----------------

entity attributes  &
     entity_name=.LWR_6DOF_GRABER.GRABER  &
     color=MAIZE  &
     name_visibility=OFF


default command echo=on
