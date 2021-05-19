syx = {};

syx.Effect = require("Audio.Effect");
syx.Music = require("Audio.Music");
syx.Sound = require("Audio.Sound");

syx.BaseScene = require("Base.Scene.BaseScene");
syx.ILoadingScene = require("Base.Scene.ILoadingScene");

syx.Label = require("Classes.Label");
syx.Timer = require("Classes.Timer");

syx.DeadState = require("FSM.DeadState");
syx.FSM = require("FSM.FSM");
syx.InitState = require("FSM.InitState");
syx.IState = require("FSM.IState");

syx.RatePool = require("Math.Algorithm.RatePool");
syx.Stack = require("Math.Algorithm.Stack");

syx.Circle = require("Math.Geometry.Circle");
syx.IShape = require("Math.Geometry.IShape");
syx.Polygon = require("Math.Geometry.Polygon");
syx.Sector = require("Math.Geometry.Sector");
syx.Vector = require("Math.Geometry.Vector");

syx.Client = require("Network.Socket.Client");
syx.Connection = require("Network.Socket.Connection");
syx.Server = require("Network.Socket.Server");
syx.WebSocket = require("Network.Socket.WebSocket");

syx.Downloader = require("Network.Downloader");
syx.HttpInvoker = require("Network.HttpInvoker");

syx.Device = require("Platform.Device");

syx.LocalFile = require("Utils.LocalFile");
syx.UserFile = require("Utils.UserFile");
syx.ZipFile = require("Utils.ZipFile");

syx.VersionManager = require("Module.VersionManager");