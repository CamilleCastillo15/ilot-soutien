/** OTHER **/
'use strict';

var browserSync = require('browser-sync');
var importer = require('node-sass-globbing');
var gulp = require('gulp');
var sass = require('gulp-sass');
var compass = require('gulp-compass');

var rename = require('gulp-rename');
var uglify = require('gulp-uglify');
//var notify = require('gulp-notify');
var minifyCSS = require('gulp-minify-css');

var sourcemaps = require('gulp-sourcemaps');
var autoprefixer = require('gulp-autoprefixer');
var handlebars = require('gulp-handlebars');

var wrap = require('gulp-wrap');
var declare = require('gulp-declare');
var concat = require('gulp-concat');

gulp.task('sass:dev', function () {
     gulp.src('./sass/**/*.scss')
        .pipe(sourcemaps.init())
        .pipe(sass({
            importer: importer,
            includePaths: [
                'node_modules/singularitygs/stylesheets/',
                'node_modules/breakpoint-sass/stylesheets/'
            ]
        }).on('error', sass.logError))

            .pipe(autoprefixer({
                browsers: ['last 4 version']
            }))
        .pipe(sourcemaps.write('.'))
  	    .pipe(concat("all.css"))
        .pipe(gulp.dest('./css'))
        .pipe(browserSync.stream({match: '**/*.css'}));
//        .pipe(notify({ message: 'Styles task complete' }));
});

gulp.task('sass:watch', function () {
    gulp.watch('./sass/**/*.scss',function() {
        setTimeout(function () {
            gulp.start('sass:dev');
        }, 300);
    } );
    gulp.watch('./**/*.{php,inc,info,js}', ['reload']);
});

gulp.task('browser-sync',['sass:dev'], function() {
 browserSync.init({
   proxy: "",
   socket: {
       domain: 'actolis.dinde.pro:3000'
   },
   ghostMode: {
    clicks: true,
    forms: true,
    scroll: false
   }
 });
});

gulp.task('reload', function () {
    browserSync.reload();
});

gulp.task('default', ['sass:dev','sass:watch','browser-sync']);
