[Variables]

BarHeight=#WORKAREAHEIGHT#
BarWidth=62
BarColour=32,34,37

IconSize=45
IconPadding=6

SelectedIconRadius=15

IndicatorColour=138, 142, 148
SelectedIndicatorColour=255,255,255

TooltipColour=0,0,0
TooltipTextColour=255,255,255
TooltipTextSize=8
TooltipFont=Open Sans
;Discord uses Whitney but ew proprietary

;---------------------------------------------------;
;DON'T TOUCH BELOW UNLESS YOU KNOW WHAT YOU'RE DOING;
;---------------------------------------------------;

ClampedSize=(max(#BarWidth#,(#IconSize#+#IconPadding#))+5)