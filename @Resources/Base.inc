[Rainmeter]
Update=100
DynamicWindowSize=1
OnRefreshAction=[!SetOption TooltipBackground DynamicVariables 0]

@IncludeVariables=#@#Variables.inc

;Measures

[AppPoll]
Measure=Plugin
Plugin=Process
ProcessName=#AppProcess#
Substitute="-1":"0"
UpdateDivider=50
OnChangeAction=[!UpdateMeasure CornerRadius]

[CornerRadius]
Measure=Loop 
StartValue=(#IconSize#*0.5)
EndValue=#SelectedIconRadius#
Increment=-1
LoopCount=1
InvertMeasure=([AppPoll]=1 ? 1 : 0)
IfEqualValue=#SelectedIconRadius#
IfEqualAction=[!SetOption #CurrentSection# "UpdateDivider" "-1"]
OnChangeAction=[!SetOption Overlay DynamicVariables 0]

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
MouseOverAction=[!SetOption TooltipBackground Modifiers "StrokeWidth 0 | Fill Color #*TooltipColour*#"][!SetOption TooltipText InlineSetting2 "Color | #*TooltipTextColour*#"][!Update]
MouseLeaveAction=[!SetOption TooltipBackground Modifiers "StrokeWidth 0 | Fill Color 0,0,0,0"][!SetOption TooltipText InlineSetting2 "Color | 0,0,0,0"][!Update]

[Overlay]
Meter=Shape
Shape=Rectangle 0,0,#ClampedSize#,(#IconSize#+#IconPadding#) | StrokeWidth 0 | Fill Color #BarColour#
Shape2=Rectangle ((#IconPadding#*0.5)+(((#ClampedSize#-#IconPadding#)-#IconSize#)*0.5)),(#IconPadding#*0.5),#IconSize#, #IconSize#,([CornerRadius])
Shape3=Combine Shape | XOR Shape2
;Indicator
Shape4=Rectangle -5,((#IconSize#+#IconPadding#)*0.5-(5+(15*[AppPoll]))),10,(10+(30*[AppPoll])),5 | StrokeWidth 0 | Extend IndicatorModifiers
IndicatorModifiers=Fill Color #IndicatorColour#

[TooltipBackground]
Meter=Shape
X=(#ClampedSize#-(#IconPadding#*0.5))
Y=(((#IconSize#+#IconPadding#)*0.5)-(([TooltipText:H]+16)*0.5))
Shape=Path TooltipTriangle | Extend Modifiers
Shape2=Rectangle 4,0,([TooltipText:W]+24),([TooltipText:H]+16),4 | Extend Modifiers
TooltipTriangle=0,(([TooltipText:H]+16)*0.5) | LineTo 4,(([TooltipText:H]+16)*0.5+4) | LineTo 4,(([TooltipText:H]+16)*0.5-4) | ClosePath 1
Modifiers=StrokeWidth 0 | Fill Color 0,0,0,0
UpdateDivider=10

[TooltipText]
Meter=String
Text=#AppName#
AntiAlias=1
X=16r
Y=8r
InlineSetting=Face | #TooltipFont#
InlineSetting2=Color | 0,0,0,0
InlineSetting3=Size | #TooltipTextSize#
UpdateDivider=10