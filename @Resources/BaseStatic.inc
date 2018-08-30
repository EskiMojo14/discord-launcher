[Rainmeter]
Update=100
DynamicWindowSize=1
OnRefreshAction=[!SetOption TooltipBackground DynamicVariables 0]

@IncludeVariables=#@#Variables.inc

[Variables]
MouseOver=1

;Measures

[AppPoll]
Measure=Plugin
Plugin=Process
ProcessName=#AppProcess#
UpdateDivider=50
OnChangeAction=[!UpdateMeter Overlay][!Redraw]

;Meters

[Background]
Meter=Shape
Shape=Rectangle 0,0,#ClampedSize#,(#IconSize#+#IconPadding#) | StrokeWidth 0 | Fill Color #BarColour#

[Icon]
Meter=Image
ImageName=#AppIcon#
W=#IconSize#
H=#IconSize#
X=((#IconPadding#*0.5)+(((#ClampedSize#-#IconPadding#)-#IconSize#)*0.5))
Y=(#IconPadding#*0.5)
AntiAlias=1
LeftMouseUpAction=[#AppShortcut#]
MouseOverAction=[!SetOption TooltipBackground Modifiers "StrokeWidth 0 | Fill Color #*TooltipColour*#"][!SetOption TooltipText InlineSetting2 "Color | #*TooltipTextColour*#"][!SetVariable MouseOver "1"][!Update]
MouseLeaveAction=[!SetOption TooltipBackground Modifiers "StrokeWidth 0 | Fill Color 0,0,0,0"][!SetOption TooltipText InlineSetting2 "Color | 0,0,0,0"][!SetVariable MouseOver "0"][!Update]

[Overlay]
Meter=Shape
Shape=Rectangle 0,0,#ClampedSize#,(#IconSize#+#IconPadding#) | StrokeWidth 0 | Fill Color #BarColour#
Shape2=Rectangle ((#IconPadding#*0.5)+(((#ClampedSize#-#IconPadding#)-#IconSize#)*0.5)),(#IconPadding#*0.5),#IconSize#, #IconSize#,([AppPoll]=1 ? #SelectedIconRadius# : (#MouseOver#=1 ? #SelectedIconRadius# : (#IconSize#*0.5)))
Shape3=Combine Shape | XOR Shape2
;Indicator
Shape4=Rectangle -5,((#IconSize#+#IconPadding#)*0.5-([AppPoll]=1 ? 20 : 5)),10,([AppPoll]=1 ? 40 : 10),5 | StrokeWidth 0 | Extend IndicatorModifiers
IndicatorModifiers=Fill Color #IndicatorColour#

[TooltipBackground]
Meter=Shape
X=(#ClampedSize#-(#IconPadding#*0.5))
Y=(((#IconSize#+#IconPadding#)*0.5)-(([TooltipText:H]+4)*0.5))
Shape=Path TooltipTriangle | Extend Modifiers
Shape2=Rectangle 4,0,([TooltipText:W]+24),([TooltipText:H]+8),4 | Extend Modifiers
TooltipTriangle=0,(([TooltipText:H]+8)*0.5) | LineTo 4,(([TooltipText:H]+8)*0.5+4) | LineTo 4,(([TooltipText:H]+8)*0.5-4) | ClosePath 1
Modifiers=StrokeWidth 0 | Fill Color 0,0,0,0
UpdateDivider=10

[TooltipText]
Meter=String
Text=#AppName#
AntiAlias=1
X=16r
Y=4r
InlineSetting=Face | #TooltipFont#
InlineSetting2=Color | 0,0,0,0
InlineSetting3=Size | #TooltipTextSize#
UpdateDivider=10