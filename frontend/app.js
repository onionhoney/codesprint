/*
 * Module dependencies.
 */
const express = require('express'); // express framework for node.js
const path = require('path'); // utilities for working with file and directory paths
const cookieParser = require('cookie-parser'); // working with cookies
const chalk = require('chalk'); // pretty command line colors
const bodyParser = require('body-parser');
const dotenv = require('dotenv');
/*
 * TODO: Load environment variables from .env file, where API keys and passwords are configured.
 */
//dotenv.load({ path: '.env' });
//dotenv.config({path: __dirname + '/.env'});

/*
 * Controllers (route handlers).
 */
const homeController = require('./controllers/home');

/*
 * API keys and Passport configuration.
 */
//const passportConfig = require('./config/passport');

/*
 * Create Express server.
 */
const app = express();

/*
 * Express configuration.
 */
app.set('port', process.env.PORT || 8080);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));


/*
 * Primary app routes.
 */
app.get('/', homeController.home);

/**
 * Start Express server.
 */

var server = app.listen(app.get('port'), function(){
    console.log('%s Express server listening on port %d.', chalk.green('✓'), app.get('port'));
});

