object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Student database'
  ClientHeight = 311
  ClientWidth = 1104
  Color = clBtnFace
  Constraints.MaxHeight = 350
  Constraints.MaxWidth = 1120
  Constraints.MinHeight = 350
  Constraints.MinWidth = 1120
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 13
    Width = 117
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
  end
  object Label2: TLabel
    Left = 8
    Top = 173
    Width = 95
    Height = 13
    Caption = #1042#1074#1086#1076' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093
  end
  object Edit1: TEdit
    Left = 8
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 8
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 59
    Width = 121
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 219
    Width = 121
    Height = 25
    Caption = #1042#1074#1077#1089#1090#1080
    TabOrder = 3
    OnClick = Button2Click
  end
  object StringGrid1: TStringGrid
    Left = 224
    Top = 8
    Width = 599
    Height = 241
    ColCount = 6
    DefaultColWidth = 98
    DefaultRowHeight = 33
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 4
  end
  object StringGrid2: TStringGrid
    Left = 224
    Top = 401
    Width = 599
    Height = 241
    ColCount = 6
    DefaultColWidth = 98
    DefaultRowHeight = 30
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 5
    Visible = False
  end
  object ListBox1: TListBox
    Left = 829
    Top = 8
    Width = 274
    Height = 241
    ItemHeight = 13
    TabOrder = 6
  end
  object Button3: TButton
    Left = 224
    Top = 255
    Width = 121
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 981
    Top = 255
    Width = 122
    Height = 25
    Caption = #1042#1099#1074#1077#1089#1090#1080' '#1087#1086' '#1075#1088#1091#1087#1087#1077
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 829
    Top = 617
    Width = 114
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
    TabOrder = 9
    Visible = False
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 686
    Top = 255
    Width = 137
    Height = 25
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1080
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 278
    Width = 121
    Height = 25
    Caption = #1057#1074#1077#1088#1085#1091#1090#1100'/'#1056#1072#1079#1074#1077#1088#1085#1091#1090#1100
    TabOrder = 11
    OnClick = Button7Click
  end
  object OpenDialog1: TOpenDialog
    Left = 136
    Top = 224
  end
  object OpenDialog2: TOpenDialog
    Left = 360
    Top = 256
  end
  object OpenDialog3: TOpenDialog
    Left = 952
    Top = 608
  end
end
